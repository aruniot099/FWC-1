/*Code by G. Arun Kumar (works on termux)
Feb 16, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the ratio in which the line segement joining the points R(−3,10) and (6,−8) is divide by (−1,6)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"	//Include the functions from the lib.h

int main() {
    double **a, **b, **c, **d;   //Declaring all the variables
    double x, y, z;
    int m = 2, n = 1, i, j;

    a = loadtxt("a.dat", 2, 1);   // Loading the point A from the text file
    b = loadtxt("b.dat", 2, 1);   // Loading the point B from the text file
    c = loadtxt("c.dat", 2, 1);   // Loading the point C from the text file
    d = loadtxt("d.dat", 2, 1);   // Loading the point D from the text file

    x=0.5*(linalg_norm(cross(linalg_sub(a,b,m,n),linalg_sub(a,d,m,n))));    //Finding the area of the first triangle
    y=0.5*(linalg_norm(cross(linalg_sub(b,c,m,n),linalg_sub(b,d,m,n))));    //Finding the area of the second triangle

    z=x+y;    //Area of Quadrilateral

    printf("The area of quadrilateral is %lf",z);
    // Return the value of x to be used in Python
    return z;
}

