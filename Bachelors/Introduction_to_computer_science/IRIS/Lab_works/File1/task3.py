from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot( projection ='3d')
# Set the axis labels
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
# Rotate the axes and update
for pitch in range (0, 90) :
    yaw = roll = 0
    # Update the axis view and title
    ax.view_init(pitch , yaw , roll )
    plt.title('Pitch : % d , Yaw : % d , Roll : % d ' % (pitch , yaw , roll ))
    plt.draw()
    plt.pause(.001)