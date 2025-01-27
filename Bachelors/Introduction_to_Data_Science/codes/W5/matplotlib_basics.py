import matplotlib.pyplot as plt
import numpy as np

#example 1
# Data
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Create a line plot
plt.plot(x, y)

# Show the plot
plt.show()

#example 2 
# Data
x = [1, 2, 3, 4, 5]
y = [2, 4, 6, 8, 10]

# Create a line plot with customizations
plt.plot(x, y, label='My Line Plot', c='red', linestyle='--', marker='o')

# Add labels and a title
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('My First Matplotlib Plot')

# Add a legend
plt.legend()

# Show the plot
plt.show()

# Here is a summary of the features of `plt.plot()` we explored already in a previous section.

# - Calling the plot function with only one argument `y` displays the values `y[k]` versus the indices `k`, either connected by straight line segments, or as individual points using predefined plot symbols.
# - With two arguments `x` and `y`, the values `y[k]` are displayed versus the values `x[k]` for all valid indices `k`.
# - The linestyle can be controlled through the keyword parameter `linestyle` (or `ls`).
# - The linewidth can be specified using the keyword parameter `linewidth` (or `lw`).
# - The color can be controlled through the keyword parameter `color` (or `c`).
# - Marker symbols can be added using the keyword parameter `marker` (or `m`).

# Some of the functionality is also available through *format strings*, e.g., `'r--'` produces a plot with data connected by red dashed lines.


#When `plot()` or another plotting function such as `scatter()` or `imshow()` is called, the output becomes part of an implicitly generated figure object. Although such an automatic generation is convenient, it is usually cleaner and more robust to explicitly open figure objects, e.g., using the function `figure()`. The resulting object can be stored in a  variety of graphics formats by means of the function `savefig()`.
fig = plt.figure(figsize=(8,5))
plt.plot(np.cos(np.pi*np.linspace(-1,1,5)/2))
plt.show()


#Plot title and axes annotations can be added in successive command lines with string variables as arguments. A legend is constructed using the strings provided in `plot()` with the keyword `label`. You may also add a grid for better readability of numerical values.

### Equidistant discretization of [-1,1] with spacing 0.5.
x = np.linspace(-1,1,5)
### Definition of grid function.
y = np.cos(np.pi*x/2)
### Open a new figure object of default size.
plt.figure()
### Create a black line plot of y versus x, set label to be used in legend().
plt.plot(x,y,color='k',label='Line segments')
### Mark grid points with red circles.
plt.plot(x,y,'ro',label='Marker symbols')
### Add a straight line at y=0.5.
plt.plot(x,0.5*np.ones(len(x)),'g--',label='Straight line')
### Add plot title and axes annotations.
plt.title('A simple plot')
plt.xlabel('x axis')
plt.ylabel('y axis')
### Construct a plot legend from labels set in the previous calls to plot().
plt.legend()
### Add a grid for better readability of numerical values.
plt.grid()
plt.show()


#this shows what linespace does

# Create an array with 5 equally spaced values from 0 to 1 (inclusive)
arr = np.linspace(0, 1, num=5)

print(arr)



