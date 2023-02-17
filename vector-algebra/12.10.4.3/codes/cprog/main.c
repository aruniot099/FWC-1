/*Code by G. Arun Kumar (works on termux)
Feb 17, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
To find components of vector a, if unit vector a makes angles π/3 with i, π/4 with j and an acute angle θ with k, then find the components of a.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h" // user-defined library that contains required functions

int main() {
    double **a;
    int m = 3, n = 1;
    
    // create a 3x1 matrix to hold the values of a
    a = createMat(m, n);
    
    // calculate the values of a
    a[0][0] = cos(M_PI / 3);
    a[1][0] = cos(M_PI / 4);
    a[2][0] = sqrt(1 - pow(a[0][0], 2) - pow(a[1][0], 2));
    
    // print the values of a
    printf("The components of vector A are: ");
    print(a, m, n);
    
    
    return 0;
}

