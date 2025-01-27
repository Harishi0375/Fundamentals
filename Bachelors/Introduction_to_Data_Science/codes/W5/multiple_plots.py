import matplotlib.pyplot as plt
import numpy as np

### Equidistant discretization of [-1,1] with spacing 0.1.
x = np.linspace(-1,1,21)
### Definition of grid functions.
y1 = x
y2 = x**2
y3 = x**3
### Open a new figure object of default size.
plt.figure(figsize=(10,6))
### First plot in a (2,3) array.
plt.subplot(2,3,1)
plt.plot(x,y1,color='k')
plt.title(r'Function $y=x$')
plt.ylabel('y axis')
### Second plot in a (2,3) array.
plt.subplot(2,3,2)
plt.plot(x,y2,color='k')
plt.title(r'Function $y=x^2$')
### Third plot in a (2,3) array.
plt.subplot(2,3,3)
plt.plot(x,y3,color='k')
plt.title(r'Function $y=x^3$')
### Fourth plot in a (2,3) array.
plt.subplot(2,3,4)
plt.plot(x,y1,'go')
plt.xlabel('x axis')
plt.ylabel('y axis')
### Fifth plot in a (2,3) array.
plt.subplot(2,3,5)
plt.plot(x,y2,'go')
plt.xlabel('x axis')
### Sixth plot in a (2,3) array.
plt.subplot(2,3,6)
plt.plot(x,y3,'go')
plt.xlabel('x axis')
plt.show()