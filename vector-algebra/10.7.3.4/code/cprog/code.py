#Code by G. Arun Kumar(Works on Termux)
#16th Feb
#Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt

import ctypes
  
# Load the shared object file
libmain = ctypes.CDLL('./libmain.so')

# Call the function from the shared object file
area = libmain.main()

#Two aray vectors are given  
A = np.loadtxt('a.dat',dtype='float') 
B = np.loadtxt('b.dat',dtype='float')
C = np.loadtxt('c.dat',dtype='float')
D = np.loadtxt('d.dat',dtype='float')
 
print ("Area of quadrilateral ABCD is", area)


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
x_CD = line_gen(C,D)
x_DA= line_gen(D,A)

#
#
#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:],label='$AB$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$BC$')
plt.plot(x_CD[0,:],x_CD[1,:],label='$CD$')
plt.plot(x_DA[0,:],x_DA[1,:],label='$DA$')
#
#
#Labeling the coordinates
tri_coords = np.vstack((A,B,C,D)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A''(-4,-2)','B''(-3,-5)','C''(3,-2)','D''(2,3)']
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
plt.title('Area of Quadrilateral ABCD',size=12) 

#if using termux
plt.savefig('/sdcard/FWC/figures/vectors/fig3.pdf')
#else
#plt.show()

