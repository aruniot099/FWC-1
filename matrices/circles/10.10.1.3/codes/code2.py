#Python libraries for math and graphics
import numpy as np
import mpmath as mp
import matplotlib.pyplot as plt
from numpy import linalg as LA

import sys  
sys.path.insert(0,'/sdcard/FWC/CoordGeo')


#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#if using termux
import subprocess
import shlex
#end if
#Standard vectors
e1 = np.array((1,0)).reshape(2,1)
e2 = np.array((0,1)).reshape(2,1)

#Input parameters
r  = 5
d =12
Q = np.array((12,0)).reshape(2,1)
V = np.eye(2)
u = np.zeros((2,1))
f =-r**2
S = (V@Q+u)@(V@Q+u).T-(Q.T@V@Q+2*u.T@Q+f)*V
o = np.array((0,0)).reshape(2,1)
##Centre and point 
#u = np.array(([0,0]))
O = -u.T
print(O)

#Intermediate parameters

f0 = np.abs(f+u.T@LA.inv(V)@u)

#Eigenvalues and eigenvectors
D_vec,P = LA.eig(S)
lam1 = D_vec[0]
lam2 = D_vec[1]
p1 = P[:,1].reshape(2,1)
p2 = P[:,0].reshape(2,1)
D = np.diag(D_vec)

t1= np.sqrt(np.abs(D_vec))
negmat = np.block([e1,-e2])
t2 = negmat@t1
n1 = P@t1
den1 = n1.T@LA.inv(V)@n1

k1 = np.sqrt(f0/(den1))

P = LA.inv(V)@((k1*n1-u.T).T)


print(P)

#
##Generating all lines
xOQ = line_gen(o,Q)
xQP = line_gen(Q,P)
xOP = line_gen(o,P)
#
##Generating the circle
x_circ= circ_gen(O,r)
#
##Plotting all lines
plt.plot(xOQ[0,:],xOQ[1,:],label='Length of OQ')
plt.plot(xQP[0,:],xQP[1,:],label='Tangent')
plt.plot(xOP[0,:],xOP[1,:],label='Length of OP')
#

#Plotting the circle
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')
#
#
#Labeling the coordinates
tri_coords = np.vstack((Q.T,P.T,O)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['Q','P','O']
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
#
#if using termux
plt.savefig('../figs/fig.pdf')
