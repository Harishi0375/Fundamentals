import numpy as np
import matplotlib.pyplot as plt

with open("coding-labs/comma.csv", "w") as f:
    for k in range(-5,5):
        f.write("{:.1f},{:.2f}\n".format(k, k**2))

# The first argument is path to the data file.
arr = np.loadtxt("coding-labs/data.csv", delimiter=",")
# delimiters play a crucial role in structuring, parsing, 
# and processing data in various formats and contexts, 
# enabling efficient manipulation and interpretation of information.

print(arr)

#Data Output from a NumPy Array
import numpy as np
arr = np.linspace(0,1,30)
np.savetxt("coding-labs/data-from-linspace", arr, fmt="%.4f")

# #if wat to save numpy array and there is no need
# for the output to be human redable then:
import numpy as np
arr = np.linspace(0,1,11)
np.save("coding-labs/data-from-linspace", arr)

#Data Visualization
x = np.linspace(-1,1,50)
y = x**2

plt.plot(x, y, color = "r")

plt.xlabel("$x$")
plt.ylabel("$y$")
plt.title("Parabola")
plt.show()


plt.savefig("images/week03-data-visual-01.svg")

