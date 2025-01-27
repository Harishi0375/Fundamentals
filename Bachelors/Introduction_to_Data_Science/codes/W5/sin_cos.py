import matplotlib.pyplot as plt
import numpy as np

#plt.subplot(nrows, ncols, index)
#The plt.subplot function in Matplotlib is used to create subplots within a single figure. It allows you to create a grid of subplots and specify the position of the subplot in the grid. The basic syntax is:


# Create a figure with a size of (10, 6) inches
plt.figure(figsize=(10, 6))

# Create data for plotting
x = np.linspace(0, 2 * np.pi, 100)
y1 = np.sin(x)
y2 = np.cos(x)

# Plot in the first subplot (top-left position)
plt.subplot(2, 3, 1)
plt.plot(x, y1, label='sin(x)')
plt.title('Subplot 1')

# Plot in the second subplot (top-center position)
plt.subplot(2, 3, 2)
plt.plot(x, y2, label='cos(x)', color='orange')
plt.title('Subplot 2')

# Plot in the third subplot (top-right position)
plt.subplot(2, 3, 3)
plt.plot(x, y1 + y2, label='sin(x) + cos(x)', color='green')
plt.title('Subplot 3')

# Plot in the fourth subplot (bottom-left position)
plt.subplot(2, 3, 4)
plt.plot(x, y1 - y2, label='sin(x) - cos(x)', color='red')
plt.title('Subplot 4')

# Plot in the fifth subplot (bottom-center position)
plt.subplot(2, 3, 5)
plt.plot(x, y1 * y2, label='sin(x) * cos(x)', color='purple')
plt.title('Subplot 5')

# Plot in the sixth subplot (bottom-right position)
plt.subplot(2, 3, 6)
plt.plot(x, y1 / (y2 + 0.1), label='sin(x) / (cos(x) + 0.1)', color='blue')
plt.title('Subplot 6')

# Adjust layout for better spacing
plt.tight_layout()

# Show the entire figure
plt.show()
