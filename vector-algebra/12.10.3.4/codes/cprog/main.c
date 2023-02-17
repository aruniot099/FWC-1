/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the projection of the vector i + 3j + 7k on the vector 7i − j + 8k.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lib.h" // This is the header file which includes all the math functions 

int main() {
    double **a, **b, **c, **d, e, e1, **f, **g; // initializing the variables as matrices
    int m = 3, n = 1;

    a = loadtxt("a.dat", m, n); // loading the point A from the text file
    b = loadtxt("b.dat", m, n); // loading the point B from the text file
    c = transpose(a, m, n); // Finding the Transpose of the matrix
    d = matmul(c, b, n, m, n); // Multiplication function

    e = linalg_norm(b, m); // Finding the norm of the matrix
    e1 = pow(e, 2); // finding the Square of the norm

    g = mult_float((1/e1), b, m, n);
    f = matmul(g, b, m, n, m);
    printf("The Projection of vector A on B is");
    print(f, m, n);
    save(f, m, n);
    return 0;
}

