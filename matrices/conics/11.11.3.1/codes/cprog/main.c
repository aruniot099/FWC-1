/*Code by G. Arun Kumar (works on termux)
Feb 21, 2023
Link to License("https://github.com/aruniot099/FWC-1/blob/main/License")
Find the coordinates of the focii, the vertices, the length of major and minor axes, the eccentricity and the length of the latus rectum of an ellipse whose equation is given by x^2/36 +y^2/16 = 1.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{
	// Declaring the variables
	double **v, **u, **o, **z, **A, **B, **C, **D, **F1, **F2, **G, **H, **I, **J, **N, **M, **e1;
	double **ellipAxis_A, **ellipAxis_B, **ellipMinorAxis_A, **ellipMinorAxis_B; 
	double lamda0, lamda1, fl1, fl2, lr1_Ay, lr2_Ay;
	int m=2,n=1, a=6, b=4, f=-144, f0=144;

	// Loading the matrices from text files
	v = loadtxt("v.dat", m, m);
	u = loadtxt("u.dat", m, n);
	o = loadtxt("o.dat", m, n);
	N = loadtxt("n.dat", m, n);
	e1 = loadtxt("e1.dat", m, n);
	z = loadtxt("z.dat", m, n);

	// Creating the matrices
	G = np_array(a, 0);
	H = np_array(-(a), 0);
	I = np_array(0, b);
	J = np_array(0, -(b));


	// Determining the Lamda vlaues from V matrix
	lamda0 = v[0][0];
	lamda1 = v[1][1];

        // Computing the eccentricity of ellipse
    	double e = sqrt(1 - lamda0 / lamda1);
    	double e_square = e * e;
   	printf("Eccentricity of Ellipse is %lf\n", e);

    	// Computing the Focal points 
    	F1 = mult_float(e * sqrt( f0 / (lamda1 * (1 - pow(e, 2)))), e1, m, n);
    	F2 = neg(F1, m, n);

    	// Finding the Norm values of Focal Points
    	fl1 = linalg_norm(F1, m);
    	fl2 = linalg_norm(F2, m);

    	// Determining the Directional vector
    	M = matmul(z, N, m, n, 2);

    	// Determining the points of Major Axis 
    	ellipAxis_A = mult_float(1, N, m, n);
    	ellipAxis_B = mult_float(-1, N, m, n);

    	// Determinig the points of Minor Axis
    	ellipMinorAxis_A=mult_float(1.333 / 2, M, m, n);
    	ellipMinorAxis_B=mult_float(-1.333 / 2, M, m, n);

    	lr1_Ay = sqrt((f0 - lamda0 * pow(fl1, 2)) / lamda1);
    	A = linalg_add(F1, np_array(0, lr1_Ay), m, n);
    	B = linalg_add(F1, np_array(0, -(lr1_Ay)), m, n);

    	lr2_Ay = sqrt((f0 - lamda0 * pow(fl2,2)) / lamda1);
    	C = linalg_add(F2, np_array(0, lr2_Ay), m, n);
    	D = linalg_add(F2, np_array(0, -(lr2_Ay)), m, n);

    	// Saving the results in text files
    	save(ellipAxis_A, m, n,"ellipAxis_A.dat");
    	save(ellipAxis_B, m, n, "ellipAxis_B.dat");
    	save(ellipMinorAxis_A, m, n, "ellipMinorAxis_A.dat");
    	save(ellipMinorAxis_B, m, n, "ellipMinorAxis_B.dat");
    	save(A, m, n, "A.dat");
    	save(B, m, n, "B.dat");
    	save(C, m, n, "C.dat");
    	save(D, m, n, "D.dat");
    	save(H, m, n, "H.dat");
    	save(G, m, n, "G.dat");
    	save(F1, m, n, "F1.dat");
    	save(F2, m, n, "F2.dat");
}
