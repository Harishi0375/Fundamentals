import numpy as np
from scipy import linalg as la

import RoboticsLib as rob

###################################################
# set printing options for numpy
np.set_printoptions(precision=4, suppress=True)


###################################################
# short-cuts for trigonometric functions
def s(a): return np.sin(a)
def c(a): return np.cos(a)

def d2r(a): return np.deg2rad(a)
def r2d(a): return np.rad2deg(a)

###################################################
# init figure
rfig = rob.Fig2D(min=-20, max=20)


###################################################
# frames of the 2D Rot-Rot-Transl robot arm

Fw = rob.Hmat2D() # world frame (I)
v0 = rob.Hvec2D() # origin


def F1(a1): # rotation with alpha1
    F = rob.HRot2D(a1)
    return F

F2 = rob.HTransl2D(10,0) # rigid link of length l1=10

def F3(a2): # rotation with alpha2
    F = rob.HRot2D(a2)
    return F

def F4(l2): # prismatic joint with length l2
    if l2<5 : l2=5
    if l2>10 : l2=10    
    F = rob.HTransl2D(l2,0)
    return F


###################################################
# Forward Kinematics


pg = rob.Hvec2D() # init position of the end-effector (gripper)

a1 = d2r(0.0)  # initial value for 1st DoF
a2 = d2r(0.0)  # initial value for 2nd DoF
l2 = 5.0       # initial value for 3rd DoF
q = np.array([[a1,a2,l2]]).T # the (column) vector q of the DoF (in a 2D array, i.e., as a single column in a 3x1 matrix)

# compute the Forward Kinematics (and show the frames and the arm)         
def K(q):
    
    F1I = F1(q[0,0])       
    rfig.plot_frame(F1I, size=2, label='F1I')

    F2I = F1I @ F2
    rfig.plot_frame(F2I, size=2, label='F2I')

    F3I = F2I @ F3(q[1,0]) 
    rfig.plot_frame(F3I, size=2, label='F3I')

    F4I = F3I @ F4(q[2,0]) 
    rfig.plot_frame(F4I, size=2, label='F4I')

    pg = F4I @ v0

    # draw the arm (as two lines)         
    v2 = F2I.get_transl()
    rfig.plot_line(v0, v2, linewidth=3)    
    rfig.plot_line(v2, pg, linewidth=3)    

    return pg

###################################################
# animation of the planar Rot-Rot-Transl robot arm
# 
rfig = rob.Fig2D(min=-20, max=20) # init figure

for i in range(240):
    rfig.clear()

    q[0,0] = d2r(i/3)       # some arbitrary values for a1
    q[1,0] = d2r(i/2)       # some arbitrary values for a2
    q[2,0] = 5.0+i/50.0     # some arbitrary values for l2

    pg = K(q) # compute FK and show frames plus arm
    print('position of the end-effector \n', pg, '\n')
    
    rfig.pause(0.02)

                