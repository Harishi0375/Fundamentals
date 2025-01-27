import numpy as np
import matplotlib.pyplot as plt


### Solution: NumPy `Polynomial` class ---------------------------------------------------------------------------

from numpy.polynomial import Polynomial as Poly
time,data = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
### RMS deviations for polynomials up to degree 5.
for degree in range(6):
    model = Poly.fit(time,data,degree)
    resid = data-model(time)
    print('degree: {deg:.0f}, rms deviation: {rms:.4f}'.format(
        deg=degree,rms=np.sqrt(np.mean(resid**2))))
### Compute linear and quadratic model predictions.
model1 = Poly.fit(time,data,1)
mpred1 = model1(time)
model2 = Poly.fit(time,data,2)
mpred2 = model2(time)
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
resid1 = data-mpred1
resid2 = data-mpred2
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

### Solution: Quadratic fit using scikit-learn ---------------------------------------------------------------------------------

### Select the model class.
from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=False)
### Provide the data in an appropriate format.
time,y = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
X = np.stack([np.ones(time.size),time,time**2],axis=1)
print('Shape of array X : ',X.shape)
### Fit the model to the data.
model.fit(X,y)
### Compute model predictions.
yprd = model.predict(X)
### Plot data and model predictions.
plt.plot(time,y,linewidth=2,color='red',label='Measurements')
plt.plot(time,yprd,linewidth=2,color='blue',label='Quadratic fit')
plt.title(r'Mauna Loa CO$_2$ time series')
plt.xlabel(r'Year')
plt.ylabel(r'CO$_2$ [ppm]')
plt.legend()
plt.grid()

### Solution: Cross-validation -----------------------------------------------------------------------------------------------------

### Select the model class.
from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=False)
### Provide the data in an appropriate format.
time,y = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
X = np.stack([np.ones(time.size),time,time**2],axis=1) #.. quadratic fit
### Cross-validation.
from sklearn.model_selection import cross_val_score
cross_val_score(model,X,y,cv=3)