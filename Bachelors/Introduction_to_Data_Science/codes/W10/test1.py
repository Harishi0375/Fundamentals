import numpy as np

# Example data
t = np.array([1, 2, 3, 4, 5])
m = np.array([2.3, 3.5, 4.2, 5.0, 5.8])

# Fit a linear model using polyfit
coefficients = np.polyfit(t, m, 1)

# The coefficients represent the linear model m(t) = a0*t + a1
a0 = coefficients[0]
a1 = coefficients[1]

print("Coefficients:", coefficients)
print("a0:", a0)
print("a1:", a1)