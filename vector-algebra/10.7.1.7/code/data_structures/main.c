/*Code by G. Arun Kumar (works on termux)
March 2, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
To find the point on x-axis which is equidistant from (2,-5) and (-2,9)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"  //Functions

int main() {
    Node **a, **b, **c, **e1, **e;
    double n1, n2, a1, b1, c1, N, N1;
    int m = 2, n = 1;

    // Loading the matrices from .dat files
    a = loadtxt("a.dat", m, n);
    b = loadtxt("b.dat", m, n);
    e = loadtxt("e.dat", m, n);

    // Finding the norm of the matrices
    a1 = linalg_norm(a, m, n);
    b1 = linalg_norm(b, m, n);

    // Finding the square of the norm resultant with pow() function
    n1 = pow(a1, 2);
    n2 = pow(b1, 2);

    N = n1-n2;  // Subtracting the norm values

    linalg_sub(a, b, m, n);	// Finding the Subtraction of the matrices 
    c=transpose(a,m,n);		// Finding the transpose of the matrix
    mat_val(c, n, m, 2);	// Multiplying the matrix with scalar value

    e1 = matmul(e, 2, 1, c, 1, 2);	// Multiplying the both the matrices
    c1 = e1[0][0].data;		// Taking the value of the matrix into a double value
    N1=N/c1;			// Dividing double values

    mat_val(e, m, n, N1);	// Multiplying the double value with matrix
    print(e,m, n);		// Printing the results
    save("x.dat", e, m, n);	// Saving the resultant matrix into .dat file
    return 0;
}

