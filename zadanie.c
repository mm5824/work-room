#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int *array;
	unsigned int lenght;
}MNC;

void IntersectionOfArrays(MNC *A, MNC *B) //a is lenght of A-arr, b is lenght of B-arr
{
	int i=0, j=0;

	for (i=0; i<A->lenght; i++)
	{
		for (j=0; j<B->lenght; j++)
		{
			if (A->array[i]==B->array[j])
			{
				printf ("%d  ", B->array[j]);
				j++;
			}
		}
	}
}

void UnionOfArrays(MNC *A, MNC *B)
{
	int i=0, j=0, x=0, y=0;
	int U[A->lenght+B->lenght];
	for (i=0; i<A->lenght; i++) 
	{
	        U[x]=A->array[i];
	        x++;
	}
	for (i=0; i<B->lenght; i++) 
	{
		y=0;
		for (j=0; j<A->lenght; j++) 
		{
			if (B->array[i]==A->array[j])
	                y=1;
		}
		if (y==0) 
		{
			U[x]=B->array[i];
			x++;
		}
	}

	for (i=0; i<x; i++) 
	{
		printf("%d ", U[i]);
	}
}

int main () {
	
	int a[6]={1,2,3,4,5,6};
	int b[5]={2,3,5,6};
	MNC A,B;

	A.lenght=6;
	A.array=a;
	
	B.lenght=4;
	B.array=b;

	printf("Intersection:");
	IntersectionOfArrays(&A, &B);
	printf("\nUnion:");
	UnionOfArrays(&A, &B);
}
