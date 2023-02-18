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
    double **a, **b, **o, **z, **dir, **N;
    double theta;  
    int m = 2, n = 1;

    //Defining the angle in Radians
    theta=radians(30);

    // Initialize the arrays
    a = np_array((8.0 / 3.0) * sqrt(3), 2);
    b = np_array(-(8.0 / 3.0) * sqrt(3), -2);
    dir = np_array(cos(theta), sin(theta));

    // Save the arrays to files
    save_a(a, m, n);
    save_b(b, m, n);
    save(dir, m, n);

    // Load the array from files
    o = loadtxt("o.dat", m, n);
    z = loadtxt("z.dat", 2, 2);

    // Calculate the matrix multiplication
    N = matmul(z, dir, m, 2, 2);

    // Print the result
    print(N, m, n);

    return 0;
}

