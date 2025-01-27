import numpy as np

### Define and display numerical grid x and grid function f.
x = np.array([1,2,4,6,7,8],dtype=float)
f = x**2 - 5*x - 8
print('Grid     x : ',x)
print('Function f : ',f)
print()

### Compute arithmetic means and differences.
xm = 0.5*( x[1:] + x[:-1] )
dx = x[1:] - x[:-1]
df = f[1:] - f[:-1]

### Compute approximate and exact derivatives.
dfodx_approx = df/dx #approximation
dfodx_exact  = 2*xm - 5 #exact

### Print results.
print('First derivative of function f')
print('* Array of arithmetic means         : ',xm)
print('* Finite differencing approximation : ',dfodx_approx)
print('* Evaluation of exact derivative    : ',dfodx_exact)


#IMPORTANT
# f^1(x) = dx/fx

#formulas
### Compute arithmetic means and differences.
xm = 0.5*( x[1:] + x[:-1] )
dx = x[1:] - x[:-1]
df = f[1:] - f[:-1]

### Compute approximate and exact derivatives.
dfodx_approx = df/dx
dfodx_exact  = 2*xm - 5

