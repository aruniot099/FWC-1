#p-1
#Python libraries for math and graphics 
import numpy as np 
import mpmath as mp 
import math as ma 
import matplotlib.pyplot as plt 
from numpy import linalg as LA 
 
def line_dir_pt(m,A,k1,k2): 
  len = 10 
  dim = A.shape[0] 
  x_AB = np.zeros((dim,len)) 
  lam_1 = np.linspace(k1,k2,len) 
  for i in range(len): 
    temp1 = A + lam_1[i]*m 
    x_AB[:,i]= temp1.T 
  return x_AB  
 
#Input parameters 
A= np.loadtxt('O.dat',dtype='float')                                             
n= np.loadtxt('N.dat',dtype='float')

##Generating the line  
k1=-1 
k2=1 
x_AB = line_dir_pt(n,A,k1,k2) 
 
#Plotting all lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='y=mx') 
 
    # Add labels and show the plot 

tri_coords = A.T
plt.scatter(tri_coords[0], tri_coords[1])
vert_labels = ['x(0,0)']
for i, txt in enumerate(vert_labels):
      plt.annotate(txt, # this is the text
                 (tri_coords[0], tri_coords[1]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

    # Add labels and show the plot
plt.xlabel('x')
plt.ylabel('y')
plt.title('Equation of line passing through (0,0) with slope = 2')
plt.legend(loc='best')
plt.grid()
plt.axis('equal')
    #if using termux
plt.savefig('/sdcard/FWC/figures/vectors/fig10.pdf')
