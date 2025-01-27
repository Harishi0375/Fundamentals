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

###################################################
# init figure
rfig = rob.Fig2D(min=-15, max=15)


###################################################
# frames of the 2D Rot-Transl robot arm

Fw = rob.Hmat2D() # world frame (I)
v0 = rob.Hvec2D() # origin


def F1(a): # rotation with alpha
    F = rob.HRot2D(a)
    return F


def F2(l): # prismatic joint with length l (scaled in 5-10)
    if l<5 : l=5
    if l>10 : l=10    
    F = rob.HTransl2D(l,0)
    return F


###################################################
# Forward Kinematics
pg = rob.Hvec2D() # init position of the end-effector (gripper)


a = d2r(0.0)  # initial value for 1st DoF
l = 0.0       # initial value for 3rd DoF
q = np.array([[a],[l]]) # the (column) vector q of the DoF (in a 2D array, i.e., as a single column in a 2x1 matrix)

# compute the Forward Kinematics (and show the frames and the arm)         
def K(q):    
    F1I = F1(q[0,0])       
    rfig.plot_frame(F1I, size=2, label='F1I')

    F2I = F1I @ F2(q[1,0])
    rfig.plot_frame(F2I, size=2, label='F2I')

    pg = F2I @ v0

    # draw the arm (as two lines)         
    rfig.plot_line(v0, pg, linewidth=3)    

    return pg

###################################################
# animation of the planar Rot-Transl robot arm
# 

l = 5.0             # some arbitrary start for l
for a in range(160):
    rfig.clear()

    l =l + 0.1     # some arbitrary change of l
    q[0,0] = d2r(a) # set 1st DoF 
    q[1,0] = l      # set 2nd DoF

    pg = K(q) # compute FK and show frames plus arm
    print('position of the end-effector \n', pg, '\n')
    
    rfig.pause(0.01)

