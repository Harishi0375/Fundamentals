# This tutorial explains how the Python package scikit-learn is applied to fundamental Machine Learning (ML) tasks. It builds on the companion tutorial *First steps with scikit-learn*. Follow the instructions below to learn to

# - [ ] explain key ML applications in the categories of supervised and unsupervised learning,
# - [ ] carry out basic classification and regression tasks using scikit-learn,
# - [ ] employ basic clustering methods using scikit-learn,
# - [ ] apply and appraise principal component analysis (PCA) for dimensionality reduction,
# - [ ] understand important model validation terminology and tools.

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

import seaborn as sns

### Importing scikit-learn-------------------------

import sklearn
from sklearn import datasets

# In scikit-learn, an estimator (named `model` in the following list) for a supervised learning task comes with the following generic methods.

# - `model.fit()`: fit the training data to find the instance of the model class that is closest to the observations. As arguments, the features matrix `X` and the target vector `y` must be provided.
# - `model.predict()`: once a specific instance of the model is found, compute predictions for a given set of predictor variables.
# - `model.score()`: measure the fit quality, usually in the range between 0 and 1, with better fits indicated by larger values.

## Regression ------------------------------------------------------------------------------------------------------

### Select the model class.
from sklearn.linear_model import LinearRegression
model0 = LinearRegression(fit_intercept=False)
model1 = LinearRegression(fit_intercept=False)
model2 = LinearRegression(fit_intercept=False)
### Load data, construct target vector.
time,y = np.genfromtxt('co2_mm_mlo.txt',usecols=(2,3),unpack=True)
### Construct features matrices.
X0 = np.ones(time.size)[:,np.newaxis]                   #.. fit to a constant
X1 = np.stack([np.ones(time.size),time],axis=1)         #.. linear fit
X2 = np.stack([np.ones(time.size),time,time**2],axis=1) #.. quadratic fit
### Split data for training and testing/validation.
from sklearn.model_selection import train_test_split
X0_trn,X0_val,y0_trn,y0_val = train_test_split(X0,y,train_size=0.5,random_state=99)
X1_trn,X1_val,y1_trn,y1_val = train_test_split(X1,y,train_size=0.5,random_state=99)
X2_trn,X2_val,y2_trn,y2_val = train_test_split(X2,y,train_size=0.5,random_state=99)
### Train the models.
model0.fit(X0_trn,y0_trn)
model1.fit(X1_trn,y1_trn)
model2.fit(X2_trn,y2_trn)
### Compute predictions using features for testing.
y0_prd = model0.predict(X0_val)
y1_prd = model1.predict(X1_val)
y2_prd = model2.predict(X2_val)
### Compute validation scores (R^2 relative to mean value).
print('Constant function,  validation score : ',model0.score(X0_val,y0_val))
print('Linear function,    validation score : ',model1.score(X1_val,y1_val))
print('Quadratic function, validation score : ',model2.score(X2_val,y2_val))