/*Code by G. Arun Kumar (works on termux)
Feb 13, 2023
To find the point on x-axis which is equidistant from (2,-5) and (-2,9)*/
#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"			//Functions
int main()                 
{
	double **a,**b,**f,**g,**h,**x,**y,**p,**z;		//initializing the variables as matrices
	double p1,c,c1,d,d1,e;
	int m=2,n=1,i,j,s;
	a=loadtxt("a.dat",2,1);		//loading the point A from the text file
	b=loadtxt("b.dat",2,1);		//loading the point B from the text file
	c=linalg_norm(a,m);		//Finding the norm of the matrix
	d=linalg_norm(b,m);					
	c1=c*c;				//finding the Square of the norm
	d1=d*d;
	e=c1-d1;			//Subtracting the norm values of both the input matrices
	f=linalg_sub(a,b,m,n);		//Subtraction of the matrices
	g=transpose(f,m,n);		//Finding the Transpose of the matrix
	x=loadtxt("2.dat",m,n);		//loading the 2  from the .dat file
	h=matmul(x,g,m,n,2);
	y=loadtxt("e1.dat",2,1);	//loading the e1 (1,0) from the .dat file
	p=matmul(y,h,m,n,2);
	p1=p[0][0];
	s=e/p1;				//dividing the numerator with denominator
	z=mult_int(s,y,m,n);
	print(z,m,n);			//printing the result
	save(z,m,n);			//saving the result to the figure
}
