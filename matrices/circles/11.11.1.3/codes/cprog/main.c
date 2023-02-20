/*Code by G. Arun Kumar (works on termux)
Feb 20, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Find the equation of circle with centre (1/2,1/4) and radius 1/12 
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	// Declaring the variables
	double **c, **u;
	double r=0.0833, f;
	int m=2, n=1;

	// Loading the matrices from the text files
	c = loadtxt("c.dat", m, n);

	// Converting the value of c to negative(u=-c)
	u = neg(c, m, n);
	f = pow(linalg_norm(u,m), 2) - pow(r,2);

	// Printing the results
	print(u, m, n);
	printf("\n%lf",f);

	return r;
}
