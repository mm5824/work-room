#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int *array;
	unsigned int lenght;
}MNC;

MNC* IntersectionOfArrays(MNC *A, MNC *B) //a is lenght of A-arr, b is lenght of B-arr
{
	int i=0, j=0, x=0;
	MNC *I = malloc(sizeof(MNC));
	I->lenght = 0;

	for (i=0; i<A->lenght; i++)
	{
		for (j=0; j<B->lenght; j++)
		{
			if (A->array[i]==B->array[j])
			{
				//I->array[x]=B->array[j];
				I->lenght++;
			}
		}
	}
	
	I->array = malloc(I->lenght * sizeof(int));

	for (i=0; i<A->lenght; i++)
	{
		for (j=0; j<B->lenght; j++)
		{
			if (A->array[i]==B->array[j])
			{
				I->array[x]=B->array[j];
				x++;
			}
		}
	}

	return I;

}

void UnionOfArrays(MNC *A, MNC *B, MNC *U)
{
	int i=0, j=0, x=0, y=0;
	
	U->lenght = 0;
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
			U->lenght++;
		}
	}
	for (i=0; i<A->lenght; i++) 
	{
		U->lenght++;
	}

	U->array = malloc(U->lenght*(sizeof(int)));

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
			U->array[x]=B->array[i];
			x++;
		}
	}

	for (i=0; i<A->lenght; i++) 
	{
		U->array[x]=A->array[i];
		x++;
	}
}

int main () {
	
	int a[6]={2,4,6,8,12,10};
	int b[5]={2,3,5,6,4};
	
	MNC A,B,U;
	MNC *I;
	int i=0;

	A.lenght=6;
	A.array=a;
	
	B.lenght=5;
	B.array=b;

	printf("Intersection:");
	I=IntersectionOfArrays(&A, &B);
	
	for(i=0; i<I->lenght; i++)
	{
		printf("%d  ",I->array[i]);
	} 

	printf("\nUnion:");

	UnionOfArrays(&A, &B, &U);

	for (i=0; i<U.lenght; i++)
	{
		printf("%d ", U.array[i]);
	}
	puts(" ");

	
}
