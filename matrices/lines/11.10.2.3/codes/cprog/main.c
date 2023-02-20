/*Code by G. Arun Kumar (works on termux)
Feb 18, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the equation of line perpendicular distance from the origin is 5
units and the angle made by the perpendicular with the positive x-axis is 30.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main() {
    double **M, **N, **z; 
    int m = 2, n = 1;

    // Load the array from files
    M = loadtxt("m.dat", m, n);
    z = loadtxt("z.dat", 2, 2);

    // Calculate the matrix multiplication
    N = matmul(z, M, m, 2, 2);

    // Print the result
    print(N, m, n);

    // Saving the result
    save(N, m, n, "N.dat");

    return 0;
}

