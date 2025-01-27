import serial
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('COM5', 9600)
receivestring = ser.readline()
fig , ax = plt.subplots()
ax.set_ylim(0, 5.1)
ax.set_xlim(0, 1)
x = np.linspace(0 ,1 ,100)
y = np.zeros (100)
i = 0

while True:
    receivedata = float(ser.readline ().decode ("utf -8"). strip ())
    print( receivedata )
    if(i <100):
        y[int(i)] = receivedata
        ax.plot (x[: int(i)],y[: int(i)])
    else :
        x = np.linspace(i/100 ,i /100+1 ,100)
        for j in range(99):
            y[j] = y[j+1]
            y[99] = receivedata
            ax.set_xlim(i/100 ,i /100+1)
            ax.plot (x,y)
    fig.show()
    i += 1
    plt.pause(0.01)