import matplotlib.pyplot as plt
import numpy as np

fig , ax = plt.subplots ()
x = np. linspace (0, 100 , 100)
y = np.zeros(100); z = np.zeros(100) # y and z are two arrays with 100 zero
for i in range (100):
    y[i] = np. random.rand(); z[i] = np.random.rand() # generate random number
    ax.plot(x[:i],y[:i],x[:i],z[:i]) # plot datas from 0 to i
    fig.show()
    plt.pause(0.001) # create a 0.001 second delay