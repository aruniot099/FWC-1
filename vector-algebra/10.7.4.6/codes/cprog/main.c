/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Calculating the area of the ADE where the vertices of triangle ABC are A (4, 6), B (1, 5) and C (7, 2). A line is drawn to intersectsides AB and AC at D and E respectively ,such that AD/AB= AE/AC = 1/4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h" // User-defined functions

int main()
{
    // Initialize the variables as matrices
    double **a, **b, **c, **d, **a1, **e, **f;
    double area1, area2;
    float x, x1, z;
    int m = 2, n = 1;

    // Load points from text files
    a = loadtxt("a.dat", 2, 1);
    b = loadtxt("b.dat", 2, 1);
    c = loadtxt("c.dat", 2, 1);

    // Calculate point D and E using section formula
    x = 0.3333333333333; // Ratio is given as 3/2
    d = mult_float(1 / (1 + x), linalg_add(a, mult_float(x, b, m, n), m, n), m, n);
    e = mult_float(1 / (1 + x), linalg_add(a, mult_float(x, c, m, n), m, n), m, n);

    // Saving the results
    save(d,m,n);
    save1(e,m,n);

    // Calculate area of triangles ADE and ABC
    area1 = 0.5 * linalg_norm(cross(linalg_sub(a, d, m, n), linalg_sub(a, e, m, n)));
    area2 = 0.5 * linalg_norm(cross(linalg_sub(a, b, m, n), linalg_sub(a, c, m, n)));

    // Print the results
    printf("Area of triangle ADE: %lf\n", area1);
    printf("Area of triangle ABC: %lf\n", area2);

    return area1;
}

