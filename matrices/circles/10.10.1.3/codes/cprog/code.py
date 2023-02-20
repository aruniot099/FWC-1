#Code by G. Arun Kumar (works on termux)
#Feb 20, 2023
#Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
import numpy as np
import mpmath as mp
import matplotlib.pyplot as plt

import sys
sys.path.insert(0,'/sdcard/FWC/CoordGeo')
#path to my scripts

#local imports
from line.funcs import *
from triangle.funcs import *
#from conics.funcs import circ_gen
from conics.funcs import *

import ctypes

# Load the shared library

lib = ctypes.cdll.LoadLibrary('./libmain.so')

# Call the main function and return function
main = lib.main
r = main()
print(r)
#Circle parameters 
P = np.loadtxt('p.dat',dtype='float')
O = np.loadtxt('o.dat',dtype='float')
Q1 = np.loadtxt('Q1.dat',dtype='float')
Q2 = np.loadtxt('Q2.dat',dtype='float')

##Generating the line 
xPQ1 = line_gen(P,Q1)
xPQ2 = line_gen(P,Q2)
xOP = line_gen(O,P)
xOQ1 = line_gen(O,Q1)
xOQ2 = line_gen(O,Q2)

##Generating the circle
x_circ= circ_gen(O,r)

#Plotting all lines
plt.plot(xPQ1[0,:],xPQ1[1,:],label='Tangent $PQ_1$')
plt.plot(xPQ2[0,:],xPQ2[1,:],label='Tangent $PQ_2$')
plt.plot(xOP[0,:],xOP[1,:],label='OP')
plt.plot(xOQ1[0,:],xOQ1[1,:],label='$OQ_1$')
plt.plot(xOQ2[0,:],xOQ2[1,:],label='$OQ_2$')
#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')


#Labeling the coordinates
tri_coords = np.vstack((O,P,Q1,Q2)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','P','$Q_1$','$Q_2$']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(5,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('/sdcard/FWC/figures/vectors/fig12.pdf')
#plt.show()
