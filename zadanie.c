#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void IntersectionOfArrays(int A[], int B[], int a, int b) //a is lenght of A-arr, b is lenght of B-arr
{
	int i=0, j=0;
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			if (A[i]==B[j])
			{
				printf ("%d  ", B[j]);
				j++;
			}
		}
	}
}

void UnionOfArrays(int A[], int B[], int a, int b)
{
	int i=0, j=0, x=0, y=0;
	int U[a+b];
	for (i=0; i<a; i++) 
	{
	        U[x]=A[i];
	        x++;
	}
	for (i=0; i<b; i++) 
	{
	        y=0;
	        for (j=0; j<a; j++) 
		{
			if (B[i]==A[j])
	                y=1;
		}

		        if (y==0) 
			{
				U[x]=B[i];
				x++;
			}
		}

		printf("\nUnion:");
		for (i=0; i<x; i++) 
		{
			printf("%d ", U[i]);
		}
}

int main () {
	int A[]={1,2,3,4,5,6};
	int B[]={2,3,5,6};
	int a=6;
	int b=4;
	IntersectionOfArrays(A, B, a, b);
	UnionOfArrays(A, B, a, b);
//	printf("%d  ", IntersectionOfArrays(A, B, a, b));
	
}
