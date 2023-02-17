/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the Direction Cosines of i+2j+3k*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"	//Include the functions from the lib.h

int main() {
    double **a, **e1, **e2, **e3, **m1, **m2, **m3, **t;   //Declaring all the variables
    double n1, n2, c1, c2, c3;
    int m = 3, n = 1, i, j;

    a  = loadtxt("a.dat",  3, 1);   // Loading the point A from the text file
    e1 = loadtxt("e1.dat", 3, 1);   // Loading the point e1 from the text file
    e2 = loadtxt("e2.dat", 3, 1);   // Loading the point e2 from the text file
    e3 = loadtxt("e3.dat", 3, 1);   // Loading the point e3 from the text file

    n1 = linalg_norm(a, m);	//Finding the norm of A
    n2 = linalg_norm(e1, m);	//Finding the norm of e
    t = transpose(a, m, n);	//performing the Transpose of matrix A
    m1 = matmul(t, e1, n, m, n);	//Multiplying the matrix A with e1
    m2 = matmul(t, e2, n, m, n);	//Multiplying the matrix A with e2
    m3 = matmul(t, e3, n, m, n);	//Multiplying the matrix A with e3
    
    //Finding the direction Cosines
    c1 = m1[0][0] / (n1 * n2);
    c2 = m2[0][0] / (n1 * n2);
    c3 = m3[0][0] / (n1 * n2);
	
    //Printing the result
    printf("Direction Cosine with respect to x-axis: %lf\n", c1);
    printf("Direction Cosine with respect to y-axis: %lf\n", c2);
    printf("Direction Cosine With respect to z-axis: %lf\n", c3);
    return 0;
}

