

#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys                                          #for path to external scripts
sys.path.insert(0, '/sdcard/FWC/CoordGeo')        #path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#if using termux
import subprocess
import shlex
#end if
#Input parameters
a=5
p=12
lamda = 0.5
theta = np.arccos(a/p)
P = 12*np.array(([np.cos((90-theta)),-np.sin((90-theta))]))
Q = 5*np.array(([-np.cos((270+theta)),-np.sin((270+theta))])) 
O = np.array(([0,0]))
x_circ_1= circ_gen(O,a)
#Plotting the circle
plt.plot(x_circ_1[0,:],x_circ_1[1,:],label='Circle')


##Generating all lines
x_OP = line_gen(O,P)
x_PQ = line_gen(P,Q)
x_OQ = line_gen(O,Q)


#Plotting all lines
plt.plot(x_OP[0,:],x_OP[1,:],label='OP')
plt.plot(x_OQ[0,:],x_OQ[1,:],label='OQ')
plt.plot(x_PQ[0,:],x_PQ[1,:],label='Tangent PQ')


#Labeling the coordinates
tri_coords = np.vstack((O,P,Q,)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','P','Q']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('../figs/fig1.pdf') 
