import serial
import time
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt

ser = serial.Serial('COM7',115200)
fig = plt.figure()
ax = fig.add_subplot( projection ='3d')
# Set the axis labels
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
pitch = yaw = roll = 0
# Rotate the axes and update

def update_plot():
    while True:
        
        receivestring = ser.readline().decode("utf-8").strip() # read one line and convert bytes to a string
        receivelists = receivestring.split(',')
        if len(receivelists) == 3:
            pitch = (float(receivelists[0])*180)/3.14
            yaw = (float(receivelists[1])*180)/3.14
            roll = (float(receivelists[2])*180)/3.14
            print(pitch,yaw,roll)

            ax.clear()
            # Update the axis view and title
            ax.view_init(pitch , yaw , roll)
            ax.set_title('Pitch: %d, Yaw: %d. Roll: %d' % (pitch,yaw,roll))
            # plt.draw()
            # plt.draw()
            # plt.show()
            plt.pause(0.001)
update_plot()

    
    
    