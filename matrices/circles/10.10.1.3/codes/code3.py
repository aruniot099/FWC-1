import numpy as np
import mpmath as mp
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys
sys.path.insert(0,'/sdcard/FWC/CoordGeo')
#path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
#from conics.funcs import circ_gen
from conics.funcs import *

#if using termux
import subprocess
import shlex
#end if

#Circle parameters
r = 5
d=12
theta=np.radians 
P=np.array(([r*np.cos(theta(0)),r*np.sin(theta(0))]))
O = np.array(([0,0]))
Q =  np.array(([5,np.sqrt(119)]))
##Generating the line 
xPQ = line_gen(P,Q)
xOP = line_gen(O,P)
xOQ = line_gen(O,Q)

##Generating the circle
x_circ= circ_gen(O,r)

#Plotting all lines
plt.plot(xPQ[0,:],xPQ[1,:],label='Tangent PQ')
plt.plot(xOP[0,:],xOP[1,:],label='OP')
plt.plot(xOQ[0,:],xOQ[1,:],label='OQ')

#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


#Labeling the coordinates
tri_coords = np.vstack((O,P,Q)).T
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
plt.savefig('../figs/fig2.pdf')
#plt.show()







