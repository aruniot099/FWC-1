import numpy as np 
import matplotlib.pyplot as plt 
from numpy import linalg as LA 
import math 
import sys     #for path to external scripts 
 
 
 
 
 
#Two aray vectors are given  
A = np.array(([2, -5])) 
B = np.array(([-2, 9])) 
O = np.array(([-7, 0])) 
 
#Formula for calculating the equidistance on x-axis  
x = (np.linalg.norm(A)**2 - np.linalg.norm(B)**2) / (2 * np.transpose(A - B)) 
 
print("Equidistant point on x-axis=", x) 
 
 
 
 
def line_gen(A,B): 
   len =10 
   dim = A.shape[0] 
   x_AB = np.zeros((dim,len)) 
   lam_1 = np.linspace(0,1,len) 
   for i in range(len): 
     temp1 = A + lam_1[i]*(B-A) 
     x_AB[:,i]= temp1.T 
   return x_AB 
 
   
x_OA = line_gen(O,A) 
x_OB = line_gen(O,B) 
 
 
 
#Plotting all lines 
plt.plot(x_OA[0,:],x_OA[1,:],label='$OA$') 
plt.plot(x_OB[0,:],x_OB[1,:],label='$OB$') 
 
 
 
#Labeling the coordinates 
tri_coords = np.vstack((A,B,O)).T 
plt.scatter(tri_coords[0,:], tri_coords[1,:]) 
vert_labels = ['A','B','O'] 
for i, txt in enumerate(vert_labels): 
    plt.annotate(txt, # this is the text 
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label 
                 textcoords="offset points", # how to position the text 
                 xytext=(0,10), # distance from text to points (x,y) 
                 ha='center') # horizontal alignment can be left, right or center 
 
plt.xlabel('$x-axis$') 
plt.ylabel('$y-axis$') 
plt.legend(loc='best') 
plt.grid() # minor 
plt.axis('equal') 
plt.title('equidistant point',size=12) 
plt.text(-2,9,'   (-2,9)') 
plt.text(-7,0,'   (-7,0)') 
plt.text(2,-5,'   (2,-5)') 
  
plt.show()

