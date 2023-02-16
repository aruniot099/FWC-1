/*Code by G. Arun Kumar (works on termux)
Feb 16, 2023
Finding the ratio in which the line segement joining the points R(−3,10) and (6,−8) is divide by (−1,6)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"	//Include the functions from the lib.h

int main() {
    double **a, **b, **c, **x1, **x2, **x;   // Initializing the variables as matrices
    int m = 2, n = 1, i, j;

    a = loadtxt("a.dat", 2, 1);   // Loading the point A from the text file
    b = loadtxt("b.dat", 2, 1);   // Loading the point B from the text file
    c = loadtxt("c.dat", 2, 1);   // Loading the point C from the text file
    
    x1 = linalg_sub(a,c,m,n);     // Subtracting the matrices A and C and storing the result in x1
    x2 = linalg_sub(c,b,m,n);     // Subtracting the matrices C and B and storing the result in x2
    x  = linalg_div(x1,x2,m,n);   // Dividing the matrices x1 and x2 and storing the result in x 

    printf("Point (-1,6) divides PQ in ratio of %lf",x[0][0]);
    // Return the value of x to be used in Python
    return x[0][0];
}

