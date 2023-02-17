/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
To find the direction cosines for a line which has the direction ratios –18, 12, –4
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h" // include user-defined library that contains required functions

int main() {
    double **a, **b;
    double e;
    int m = 3, n = 1;

    // load the values of vectors A and B from files
    a = loadtxt("a.dat", m, n);
    
    // Finding the value of norm of A
    e=linalg_norm(a,m);
    
    // multplying the norm value with matrix a, B=(A/||A||)
    b=mult_float((1/e),a,m,n);

    // print the values of vector D
    printf("Direction Cosines of vector a is: \n");
    print(b, m, n);

    return 0;
}

