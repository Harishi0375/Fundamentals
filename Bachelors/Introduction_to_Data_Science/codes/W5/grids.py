import numpy as np
import matplotlib.pyplot as plt

#The following instructions produce an equidistant discretization of the interval $[a,b]$ with $N$ sub-intervals.
a = 1
b = 3
N = 4
x = np.linspace(a,b,num=N+1)
print(x)

#With numerical grids such as the array ``x``, grid functions are easily defined. The following instruction produces the set of values $ \{ f_0, f_1, f_2, \ldots\}$ with $f_n = x_n \exp(x_n)$, and stores them in the grid function `f`.
f = x*np.exp(x)
print(f)

fig = plt.figure(figsize=(8,5))
plt.plot(np.cos(np.pi*np.linspace(-1,1,5)/2))