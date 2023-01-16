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
A=  np.array(([-4,0]))
D= np.array(([(24/5),0])) 
#Direction vector 
k1=2
k2=-2
m=np.array(([k1-3,4-k1**2]))
o=np.array(([k2-3,4-k2**2]))                                                               
z=np.array(([0,1],[-1,0]))                            
n=m@z
p=o@z
print(n)
print(p) 
##Generating the line  
s=-1 
t=1 
x_AB = line_dir_pt(n,A,s,t) 
x_CD = line_dir_pt(p,D,s,t) 
 
#Plotting all lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='x=-4')  
plt.plot(x_CD[0,:],x_CD[1,:],label='x=$\dfrac{24}{5}$')  
 
    # Add labels and show the plot 
plt.xlabel('x') 
plt.ylabel('y') 
plt.title('Equation of line parallel to y-axis for k=$\pm$2') 
plt.legend(loc='best') 
plt.grid() 
plt.axis('equal') 
#plt.show()
plt.savefig('../figs/fig2.pdf')

