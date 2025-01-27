# This tutorial discusses a curve fitting example in two contexts, namely, from a traditional parametric data modeling perspective as well as an application of the Machine Learning (ML) methodology implemented in the Python package scikit-learn. Follow the instructions below to learn to

# - [ ] understand the basics of least squares parametric data modeling,
# - [ ] apply the function `polyfit()` from the NumPy module,
# - [ ] work with NumPy's `Polynomial` class,
# - [ ] understand the logic and the interface of the ML package scikit-learn,
# - [ ] apply the model class `LinearRegression`from `sklearn.linear_model`,
# - [ ] distinguish between training scores and validation scores in model evaluation.


import numpy as np
import matplotlib.pyplot as plt

### NumPy function `polyfit() --------------------------------------------------------------

#Least squares polynomial fitting is implemented in several Python libraries. To demonstrate the procedure in a basic manner, we employ the NumPy function `polyfit()`. The `fit()` method of the NumPy `Polynomial` class, recommended for reasons of numerical stability, is applied further below in an exercise. 

a0 = 1                                      #.. y-intercept of the straight line
a1 = 3                                      #.. slope of the straight line
namp = 4                                    #.. noise amplitude
time = np.linspace(0,5,21)                  #.. independent variable
gmod = a0 + a1*time                         #.. generating linear model
rng = np.random.default_rng(99)             #.. initialize random number generator
noise = namp*rng.standard_normal(time.size) #.. noise (error) term
data = gmod + noise                         #.. synthetic measurements
plt.plot(time,gmod,color='green',label='Generating model')
plt.scatter(time,data,color='blue',label='Noisy measurements')
plt.title('Straight-line fit: Synthetic data set')
plt.legend()
plt.grid()
plt.show()

# The NumPy function `polyfit()` returns the estimated polynomial coefficients in reverse order.

degree = 1
mcoef = np.polyfit(time,data,degree) #.. obtain vector of estimated model coefficients
print('Estimated y-intercept : ',mcoef[1])
print('Estimated slope       : ',mcoef[0])

#Using the estimated coefficients, the model is evaluated on the array of independent variables to yield the predictions.
mpred = np.polyval(mcoef,time)        #.. compute model predictions
plt.plot(time,gmod,color='green',label='Generating model')
plt.scatter(time,data,color='blue',label='Noisy measurements')
plt.plot(time,mpred,color='red',label='Model predictions')
plt.title('Straight-line fit: Synthetic data set and estimated model')
plt.legend()
plt.grid()
plt.show()

## Polynomial fit of the Mauna Loa CO$_2$ time series ------------------------------------------------------------------------

#The code in the following cell loads two columns from the Mauna Loa CO$_2$ data file: fractional year and monthly average CO$_2$ concentrations. The data are displayed as a time series.

### From the data file load columns (2,3) and store in two vectors.
time,data = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
plt.figure(figsize=(9,4))
plt.plot(time,data,linewidth=2,color='red')
# plt.plot(x, y, format_string, **kwargs)

# Parameters:
# x: The x-axis data (array-like or iterable)
# y: The y-axis data (array-like or iterable)
# format_string: A format string to specify the line style, marker, and color (optional)
# **kwargs: Additional keyword arguments for customization (optional)
plt.title('Mauna Loa CO$_2$ time series')
plt.xlabel('Year')
plt.ylabel('CO$_2$ [ppm]')
plt.grid()
plt.show()

# Inspection of the graph suggests that the time series can be modeled as a low-order polynomial, with annual variations of about $\pm 2$ppm and possibly random fluctuations treated as the residual. First, we try out a linear function (polynomial degree 1).
degree = 1 #degree of polynomial
mcoef = np.polyfit(time,data,degree) #np.polyfit is a NumPy function used for polynomial curve fitting, particularly for linear regression. (x,y,deg= the degree of the fitting polynomial)
print('Estimated y-intercept : ',mcoef[1])
print('Estimated slope       : ',mcoef[0])

#To check if the model predictions vary from the measurements within the expected range of $\pm 2\,$ppm, we construct the residuals and compute their average amplitude in the rms (root-mean-square) sense, i.e., the rms deviation of the data from the model. The value may also be computed by calling the NumPy function `std()` (standard deviation).

mpred = np.polyval(mcoef,time) #np.polyval(p,x) p = coefficients of the polynomial, in decreasing order and x = values at which to evaluate the polynomial. np.polyval is a NumPy function used to evaluate a polynomial at specific values
resid = data-mpred
print('rms deviation of data and model: ',np.sqrt(np.mean(resid**2)))

#This value is larger than expected, indicating that we have not yet identified the appropriate model. We thus continue with a quadratic fit of the time series.

degree = 2
mcoef = np.polyfit(time,data,degree)
mpred = np.polyval(mcoef,time)
resid = data-mpred
print('rms deviation of data and model: ',np.sqrt(np.mean(resid**2)))

#This value is consistent with the expected residual amplitude of about $\pm 2$ppm, indicating that we have identified a suitable model. To check if the residual improves further, we try out also higher-order polynomials up to degree 5. 

for degree in range(6):
    mcoef = np.polyfit(time,data,degree)
    mpred = np.polyval(mcoef,time)
    resid = data-mpred
    print('degree: {deg:.0f}, rms deviation: {rms:.4f}'.format(
        deg=degree,rms=np.sqrt(np.mean(resid**2))))
    
#The average size of the residuals does not improve signficantly if degrees larger than 2 are used in this parametric modeling exercise. To further corroborate a quadratic as an appropriate choice for the model function, we plot the data together with the linear and the quadratic models as well as histograms of the corresponding residuals. The distribution of quadratic residuals is clearly narrower than the distribution of linear residuals.
    
### Compute linear and quadratic model predictions.
mcoef1 = np.polyfit(time,data,1)
mpred1 = np.polyval(mcoef1,time)
resid1 = data-mpred1
mcoef2 = np.polyfit(time,data,2)
mpred2 = np.polyval(mcoef2,time)
resid2 = data-mpred2
plt.figure(figsize=(11,4))
### Plot measured CO2 time series and polynomial fits.
plt.subplot(121)
plt.plot(time,data,linewidth=2,color='red',label='Measurements')
plt.plot(time,mpred1,linewidth=2,color='green',label='Linear fit')
plt.plot(time,mpred2,linewidth=2,color='blue',label='Quadratic fit')
plt.title(r'Mauna Loa CO$_2$ time series')
plt.xlabel(r'Year')
plt.ylabel(r'CO$_2$ [ppm]')
plt.legend()
plt.grid()
### Compute residuals and plot histograms.
plt.subplot(122)
bin_edges = np.linspace(-15,15,31)
plt.hist(np.stack([resid1,resid2],axis=1),bins=bin_edges,color=['green','blue'],
         label=[r'Linear CO$_2$ residuals',r'Quadratic CO$_2$ residuals'])
plt.title(r'Histograms of CO$_2$ residuals')
plt.xlabel('CO$_2$ [ppm]')
plt.ylabel('Occurence frequency')
plt.xlim([-15,15])
plt.grid()
plt.legend(loc=3)