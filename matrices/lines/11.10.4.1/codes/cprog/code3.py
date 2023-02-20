#p-3
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
A= np.loadtxt('A3.dat',dtype='float')                
n= np.loadtxt('N4.dat',dtype='float')
p= np.loadtxt('N5.dat',dtype='float')

#Generating the line  
s=1 
t=-2 
u=-0.2
v=0.2
x_AB = line_dir_pt(n,A,s,t) 
x_CD = line_dir_pt(p,A,u,v) 
 
#Plotting all lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='(-2 -3)X=0')   
plt.plot(x_CD[0,:],x_CD[1,:],label='(3 32)X=0')  
 
    # Add labels and show the plot 
plt.xlabel('x') 
plt.ylabel('y') 
plt.title('Equation of line passing through origin') 
plt.legend(loc='best') 
plt.grid() 
plt.axis('equal') 
#plt.show()
plt.savefig('/sdcard/FWC/figures/vectors/fig9.pdf')

