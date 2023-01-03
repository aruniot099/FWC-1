import numpy as np 
import matplotlib.pyplot as plt 
from numpy import linalg as LA 
import math
from fractions import Fraction 

  
#Two aray vectors are given  
P = np.array(([-3, 10])) 
Q = np.array(([6, -8])) 
R = np.array(([-1, 6])) 
 
#Formula for calculating the equidistance on x-axis  
x = (Q-R)/(R-P)
 
print ('Point (-1, 6) divides the line PQ in ratio of:', Fraction(x[0]))
 
def line_gen(P,Q): 
   len =10 
   dim = P.shape[0] 
   x_PQ = np.zeros((dim,len)) 
   lam_1 = np.linspace(0,1,len) 
   for i in range(len): 
     temp1 = P + lam_1[i]*(Q-P) 
     x_PQ[:,i]= temp1.T 
   return x_PQ 
 
   
x_RP = line_gen(P,R) 
x_RQ = line_gen(R,Q) 
 
 
 
#Plotting all lines 
plt.plot(x_RP[0,:],x_RP[1,:],label='$PR$') 
plt.plot(x_RQ[0,:],x_RQ[1,:],label='$RQ$') 
 
 
 
#Labeling the coordinates 
tri_coords = np.vstack((P,Q,R)).T 
plt.scatter(tri_coords[0,:], tri_coords[1,:]) 
vert_labels = ['P','Q','R'] 
for i, txt in enumerate(vert_labels): 
    plt.annotate(txt, # this is the text 
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label 
                 textcoords="offset points", # how to position the text 
                 xytext=(10,-2), # distance from text to points (x,y) 
                 ha='center') # horizontal alignment can be left, right or center 
 
plt.xlabel('$x-axis$') 
plt.ylabel('$y-axis$') 
plt.legend(loc='best') 
plt.grid() # minor 
plt.axis('equal') 
plt.title('Point (-1,6) divides PQ in ratio of 7:2',size=12) 
plt.text(-3,10,'     (-3,10)') 
plt.text(6,-8,'      (6.-8)') 
plt.text(-1,6,'      (-1,6)')
#if using termux
plt.savefig('../figs/fig.pdf')
#else
#plt.show()
