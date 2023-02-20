#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math

import sys              #for path to external scripts
sys.path.insert(0,'/sdcard/FWC/CoordGeo')

#local imports
from conics.funcs import circ_gen

import ctypes

# Load the shared library

lib = ctypes.cdll.LoadLibrary('./libmain.so')

# Call the main function and return function
main = lib.main
main.restype = ctypes.c_double
r = main()

c = np.loadtxt('c.dat',dtype='float')

##Generating the circle
x_circ= circ_gen(c,r)

#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label = 'Circle')

#Labeling the coordinates
tri_coords = c.T  
plt.scatter(tri_coords[0], tri_coords[1])  
vert_labels = ['c'] 
for i, txt in enumerate(vert_labels):  
      plt.annotate(txt, # this is the text  
                 (tri_coords[0], tri_coords[1]), # this is the point to label  
                 textcoords="offset points", # how to position the text  
                 xytext=(0,10), # distance from text to points (x,y)  
                 ha='center') # horizontal alignment can be left, right or center



plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='upper right')
plt.grid() # minor
plt.axis('equal')
plt.savefig('/sdcard/FWC/figures/vectors/fig11.pdf')
#plt.show()
