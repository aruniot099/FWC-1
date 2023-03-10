#p-2
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
A= np.loadtxt('A2.dat',dtype='float')
D= np.loadtxt('D.dat',dtype='float')                         
n= np.loadtxt('N2.dat',dtype='float')
p= np.loadtxt('N3.dat',dtype='float')
##Generating the line  
s=-1 
t=1 
u=-5
v=5
x_AB = line_dir_pt(n,A,u,v) 
x_CD = line_dir_pt(p,D,s,t) 
 
#Plotting all lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='(-1 0)X=4') 
plt.plot(x_CD[0,:],x_CD[1,:],label='(-5 0)X=-24')  
 
    # Add labels and show the plot 
plt.xlabel('x') 
plt.ylabel('y') 
plt.title('Equation of line parallel to y-axis for k=$\pm$2') 
plt.legend(loc='upper right') 
plt.grid() 
plt.axis('equal') 
#plt.show()
plt.savefig('/sdcard/FWC/figures/vectors/fig8.pdf')

