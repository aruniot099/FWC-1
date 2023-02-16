/*Code by G. Arun Kumar (works on termux)
Feb 16, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the ratio in which the line segement joining the points R(−3,10) and (6,−8) is divide by (−1,6)*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"	//Include the functions from the lib.h

int main() {
    double **a, **b, **c;   // Initializing the variables as matrices
    double x, y, x1, x2, x3, x4;
    int m = 2, n = 1, i, j;

    a = loadtxt("a.dat", 2, 1);   // Loading the point A from the text file
    b = loadtxt("b.dat", 2, 1);   // Loading the point B from the text file
    c = loadtxt("c.dat", 2, 1);   // Loading the point C from the text file
    
    x1 = a[0][0] - c[0][0];
    x2 = c[0][0] - b[0][0];
    x3 = a[1][0] - c[1][0];
    x4 = c[1][0] - b[1][0];
    x = x1 / x2;	//Finding the ratio
    y = x3 / x4;

    printf("Point (-1,6) divides PQ in ratio of %lf",x);
    // Return the value of x to be used in Python
    return x;
}

