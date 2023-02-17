/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
To Find the the girl’s displacement from her initial point of departure, where girl walks 4 kmtowards west, then she walk 3 km in a direction 30 east of north and stops.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h" // include user-defined library that contains required functions

int main() {
    double **a, **b, **c, **d;
    double theta = 60 * M_PI / 180; // convert degrees to radians
    int m = 2, n = 1;

    // load the values of vectors A and B from files
    a = loadtxt("a.dat", m, n);
    b = loadtxt("b.dat", m, n);
    
    // create a 2x1 matrix to hold the values of vector C
    c = createMat(m, n);

    // calculate the values of vector C
    c[0][0] = 3 * cos(theta);
    c[1][0] = 3 * sin(theta);

    // add vectors B and C using the linalg_add function from the lib.h library
    d = linalg_add(b, c, m, n);

    // print the values of vector D
    printf("The girl’s displacement from her initial point of departure is:\n");
    print(d, m, n);

    return 0;
}

