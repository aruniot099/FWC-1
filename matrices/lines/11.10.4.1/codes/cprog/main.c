/*Code by G. Arun Kumar (works on termux)
Feb 20, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Find the values of k for which the line (k−3)x−(4−k^2)y+k^2−7k+6 = 0 is
(a) Parallel to the x-axis
(b) Parallel to the y-axis
(c) Passing through the origin
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main() {
    double **M1, **A1, **z, **N1, **c1, **A2, **D, **M2, **O1, **N2, **N3, **c2, **c3, **M3, **O2, **N4, **N5;
    int m = 2, n = 1;

    // Sol-1

    int k1 = 3;

    // Solving the directional vector
    M1 = np_array((k1-3),(-4+pow(k1,2)));

    // Load the array from the text file
    A1= loadtxt("A1.dat",m, n);
    z = loadtxt("z.dat", m, m);

    // Calculate the matrix multiplication
    N1 = matmul(z, M1, m, 2, 2);

    // The value of c is
    c1 = matmul(M1, A1, m, n, m);

    // Print the result
    print(N1, m, n);
    printf("The value of c is: %lf\n",c1[0][0]);

    // Saving the array to text file
    save(N1, m, n, "N1.dat");

    //Sol-2

    int k2=2, k3=-2;

    // Loading the matrix from the text file
    A2= loadtxt("A2.dat", m, n);
    D = loadtxt("D.dat", m, n);

    // Calculating the Directional vector
    M2=np_array(k2-3,4-pow(k2,2));
    O1=np_array(k3-3,4-pow(k3,2));

    // Matrix Multiplication For finding the value of Directional vector
    N2 = matmul(z, M2, m, 2, 2);
    N3 = matmul(z, O1, m, 2, 2);

    // Calculating the value of C
    c2 = matmul(M2, A2, m, n, m);
    c3 = matmul(O1, D, m, n, m);

    // Saving the value of matrix in the Text file
    save(N2, m, n, "N2.dat");
    save(N3, m, n, "N3.dat");

    // Printing the result
    print(N2,m,n);
    printf("\n");
    print(N3, m, n);
    printf("The value of c is:%lf\n",c2[0][0]);
    printf("The value of c is:%lf\n",c3[0][0]);

    //sol - 3
    int k4=1, k5 = 6;

    // Calculating the directional vector
    M3 = np_array((k4-3), (-4+pow(k4,2)));
    O2 = np_array((k5-3), (-4+pow(k5,2)));

    // Finding the normal vector
    N4 = matmul(z, M3, m, 2, 2);
    N5 = matmul(z, O2, m, 2, 2);

    // Printing the results
    print(N4, m, n);
    print(N5, m, n);

    // Saving the results
    save(N4, m, n, "N4.dat");
    save(N5, m, n, "N5.dat");

}

