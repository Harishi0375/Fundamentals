#polynomial ---------------------------------------

from numpy.polynomial import Polynomial

# Create a polynomial using coefficients
p = Polynomial([4, 3, 2, 1])

# Display the polynomial
print('Polynomial:', p)

# Evaluate the polynomial at a specific point
result = p(2)
print('Result at x = 2:', result)
