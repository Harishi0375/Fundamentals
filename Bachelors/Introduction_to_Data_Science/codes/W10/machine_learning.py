## Machine Learning (ML) approach to curve fitting ----------------------------------------------------------------------

# The polynomial fit example illustrates typical steps and choices in a modeling exercise. After 

# - *the model class is selected* (such as the polynomial class of model functions) and 
# - *the data are provided in an appropriate format*,
# - *the model is fitted to the data* (i.e., a particular instance of the model class is found that yields is closest to the obserations, such as a quadratic with a specific set of coefficients),
# - *the model predictions are computed*, and
# - *the model is validated* (i.e., the choices made in the modeling process are double-checked using a suitable metric such as the rms deviation in the polynomial fitting example above).

# To serve as a guideline for the general Machine Learning (ML) approach adopted in the Python package scikit-learn (available as `sklearn`) this list does not make explicit a central concept of parametric data modeling, namely, the set of model parameters. To make the ML approach more concrete, the Mauna Loa CO$_2$ time series fit example is revisited using the ML approach.
import numpy as np
import matplotlib.pyplot as plt

from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=False)

#### Provide the data in an appropriate format ------------------------------------------------------------------------------

#The ML package Scikit-learn expects the data in a specific format. The variable to be modeled needs to be stored in a so-called *target vector*, i.e., a one-dimensional array with its length denoted as `n_samples`. Setting the keyword `unpack` to `True`, this is accomplished by the NumPy function `genfromtxt()`. The target vector is stored in the array `y`. 

time,y = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
print('Shape of array y : ',y.shape)

#In the terminology of the regression example considered here, the basis functions are to be arranged in a so-called *features matrix* of shape `(n_samples,n_features)`. If we intend to fit a linear function $m(t) = a_0 + a_1 t$, column 0 contains an array of ones (basis function associated with the coefficient $a_0$) and column 1 contains the time array (basis function associated with the coefficient $a_1$). The features matrix is stored in the array `X`.

X = np.stack([np.ones(time.size),time],axis=1)
print('Shape of array X : ',X.shape)

### Fit the model to the data -----------------------------------------------------------------------------------------

#A scikit-learn model class is generically equipped with a `fit()` method. When called with the features matrix and the target vector, an instance of the model class is chosen that provides the best fit. If required, the model coefficients can be accessed through the `coef_` attribute.

model.fit(X,y)
print('Estimated y-intercept : ',model.coef_[0])
print('Estimated slope       : ',model.coef_[1])

### Compute model predictions -----------------------------------------------------------------------------------------

#The `predict()` method provides the model predictions.

yprd = model.predict(X)

#The predictions are plotted with the data in the same way as before.

plt.plot(time,y,linewidth=2,color='red',label='Measurements')
plt.plot(time,y,linewidth=2,color='green',label='Linear fit')
plt.title(r'Mauna Loa CO$_2$ time series')
plt.xlabel(r'Year')
plt.ylabel(r'CO$_2$ [ppm]')
plt.legend()
plt.grid()
plt.show()

#The scikit-learn interface provides the `score()` method to measure the fit quality. The output is usually in the range between 0 and 1, with better fits indicated by larger values. For the linear regression model discussed here, `score()` gives the coefficient of determination relative to a simple reference predictor, namely, the mean of the target values. If the model performs worse than the simple reference predictor, the value returned by `score()` can be negative.

model.score(X,y)
