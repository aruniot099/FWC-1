/*Code by G. Arun Kumar (works on termux)
Feb 20, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Finding the length of tangent PQ, where a tangent PQ at a point of a circle of radius 5cm meets a line through the centre O at a point Q so that OQ=12cm.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	double **p, **o, **M, **A, **b1, **Q1, **Q2, **A0, **M0;
	double theta, a1, M1, a, b, c;
	int m=2, n=1, r=5, d=12;
	
	// Finding the point on circle
	theta=radians(0);   	
        p=np_array(r*cos(theta),r*sin(theta));
	save(p,m,n,"p.dat");	//Saving the result in matrix format

	// Loading the matrices from a text file
	A = loadtxt("a.dat", m, n);
	M = loadtxt("m.dat", m, n);
	o = loadtxt("o.dat", m, n);
	A0 = loadtxt("a.dat", m, n);
	M0 = loadtxt("m.dat", m, n);

	// Finding the Norm values
	a1 = linalg_norm(A, m);
	M1 = linalg_norm(M, m);

	/*Parametric equation
	Q=A+xm(where, x=lamda)
	x^2||m||^2+2xA^tm+||A||^2=d^2*/
	// Finding the values of Co-efficients of a Quadratic Equation
	a = pow(M1,2);
	b1 = mult_int(2,(matmul(A,M,m,n,2)),m,n);
	b = b1[0][0];
	c = pow(a1,2)-pow(d,2);

	//Finding the roots from a Quadratic equation
    double discriminant = b*b - 4*a*c;

    double root1 = (-b + sqrt(discriminant)) / (2*a);
    double root2 = (-b - sqrt(discriminant)) / (2*a);

    printf("Root 1: %lf\n", root1);
    printf("Root 2: %lf\n", root2);

    // Calculating the values of points Q1, Q2
    Q1 = linalg_add(A, (mult_float(root1, M, m, n)), m, n);
    Q2 = linalg_add(A0, (mult_float(root2, M0, m, n)), m, n);

    // Printing the value of Q1 and Q2
    print(Q1, m, n);
    print(Q2, m, n);

    // Saving the result of points Q1 & Q2 in text files
    save(Q1, m, n, "Q1.dat");
    save(Q2, m, n, "Q2.dat");

    return r;
}
