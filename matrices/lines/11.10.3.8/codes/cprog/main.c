/*Code by G. Arun Kumar (works on termux)
Feb 18, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the equation of line perpendicular to the line x − 7y + 5 = 0 and
having x intercept 3.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main() {
    double **a, **d, **z, **M, **N;
    int m = 2, n = 1;

    // Load the array from files
    a = loadtxt("a.dat", m, n);
    d = loadtxt("d.dat", m, n);
    M = loadtxt("m.dat", m, n);
    z = loadtxt("z.dat", 2, 2);

    // Calculate the matrix multiplication
    N = matmul(z, M, m, 2, 2);

    // Print the result
    print(N, m, n);

    // Saving the Result
    save(N,m,n);

    return 0;
}

