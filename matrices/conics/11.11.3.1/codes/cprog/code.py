#Code by G. Arun Kumar (works on termux)
#Feb 21, 2023
#Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")

#Python libraries for math and graphics
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
from math import *
import matplotlib.cm as cm
import matplotlib.legend as Legend

import sys                                          #for path to external scripts
sys.path.insert(0,'/sdcard/FWC/CoordGeo')
#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import ellipse_gen
from params import *
#if using termux
import subprocess
import shlex
#end if

def affine_transform(P,c,x):
    return P@x + c

#Input parameters
a=6
b=4
ellipAxis_A= np.loadtxt('ellipAxis_A.dat',dtype='double')
ellipAxis_B= np.loadtxt('ellipAxis_B.dat',dtype='double')
ellipMinorAxis_A=np.loadtxt('ellipMinorAxis_A.dat',dtype='float')
ellipMinorAxis_B=np.loadtxt('ellipMinorAxis_B.dat',dtype='float')
A=np.loadtxt('A.dat',dtype='float')
B=np.loadtxt('B.dat',dtype='float')
C=np.loadtxt('C.dat',dtype='float')
D=np.loadtxt('D.dat',dtype='float')
H=np.loadtxt('H.dat',dtype='float')
G=np.loadtxt('G.dat',dtype='float')
F1=np.loadtxt('F1.dat',dtype='float')
F2=np.loadtxt('F2.dat',dtype='float')

#Generating the ellipse
elli=  ellipse_gen(a,b) 

# Generating lines 
x_AB = line_gen(ellipAxis_A, ellipAxis_B)
x_minor_AB = line_gen(ellipMinorAxis_A, ellipMinorAxis_B)
x_lr1_AB = line_gen(A , B )
x_lr2_CD = line_gen(C , D )

#Plotting the ellipse
plt.plot(elli[0,:],elli[1,:],label='$Ellipse$')

leg_label = "{} {}".format("Major", "Axis")
plt.plot(x_AB[0,:],x_AB[1,:] ,label = leg_label)

leg_label = "{} {}".format("Minor", "Axis")
plt.plot(x_minor_AB[0,:],x_minor_AB[1,:] ,label = leg_label)

leg_label = "{} {}".format("Latus", "Rectum1")
plt.plot(x_lr1_AB[0,:],x_lr1_AB[1,:] ,label = leg_label)

leg_label = "{} {}".format("Latus", "Rectum2")
plt.plot(x_lr2_CD[0,:],x_lr2_CD[1,:] ,label = leg_label)


#Labeling the coordinates
plot_coords = np.vstack((F1,F2,H,G)).T
vert_labels = ['$F_1$','$F_2$','$V_1$','$V_2$']
for i, txt in enumerate(vert_labels):
    if ( i == 0) :
      label = "{}".format('$F_1 - Focus 1$' )
    elif ( i == 1) :
      label = "{}".format('$F_2 - Focus 2$' )
    elif ( i == 2) :
      label = "{}".format('$V_1 - Vertex 1$' )
    else :
      label = "{}".format('$V_2 - Vertex 2$' )

    plt.scatter(plot_coords[0,i], plot_coords[1,i], s=15, label = label)
    plt.annotate(txt, # this is the text
                (plot_coords[0,i], plot_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(8,5), # distance from text to points (x,y)
                 fontsize=7,
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')

plt.gca().legend(loc='lower left', prop={'size':6},bbox_to_anchor=(0.93,0.6))
plt.grid() # minor

plt.axis('equal')
plt.title('Ellipse')
#if using termux
plt.savefig('/sdcard/FWC/figures/vectors/fig13.pdf')
#else
#plt.show()
