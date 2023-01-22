import numpy as np  
import matplotlib.pyplot as plt  
from numpy import linalg as LA  
import math 
from fractions import Fraction  
 
b1=3 * np.cos(np.radians(60)) 
b2=3 * np.sin(np.radians(60)) 
#Two aray vectors are given   
A = np.array(([0, 0])) 
B = np.array(([-4, 0]))  
C = np.array(([b1, b2]))  
 
# Net displacement: add the two displacements together 
D = B+C 
print(D) 
print(b1,b2) 
 
def line_gen(A,B): 
   len =10 
   dim = A.shape[0] 
   x_AB = np.zeros((dim,len)) 
   lam_1 = np.linspace(0,1,len) 
   for i in range(len): 
     temp1 = A + lam_1[i]*(B-A) 
     x_AB[:,i]= temp1.T 
   return x_AB 
# 
#Generating all lines 
x_AB = line_gen(A,B) 
x_BC= line_gen(B,C) 
x_AC = line_gen(C,A) 
 
 
# 
# 
#Plotting all lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='$B-A$') 
plt.plot(x_BC[0,:],x_BC[1,:],label='$C-B$') 
plt.plot(x_AC[0,:],x_AC[1,:],label='$A-C$') 
# 
# 
#Labeling the coordinates 
tri_coords = np.vstack((A,B,C)).T 
plt.scatter(tri_coords[0,:], tri_coords[1,:]) 
vert_labels = ['A''  (0,0)','B''(-4,0)','C'' ($\dfrac{3}{2}$,$\dfrac{3\sqrt{3}}{2}$)'] 
for i, txt in enumerate(vert_labels): 
    plt.annotate(txt, # this is the text 
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text 
                 xytext=(0,-19), # distance from text to points (x,y) 
                 ha='center') # horizontal alignment can be left, right or center 
 
plt.xlabel('East') 
plt.ylabel('North') 
plt.legend(loc='best') 
plt.grid() # minor 
plt.axis('equal') 
plt.title('Initial Displacement ($\dfrac{-5}{2}$,$\dfrac{3\sqrt{3}}{2}$)') 
#if using termux 
plt.savefig('../figs/fig.pdf') 
#else 
#plt.show()
