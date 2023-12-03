#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int getsum(int arr[], int n)
{
	int i, sum=0;
	for(i=0; i<n; i++)
		sum+= arr[i];
	return sum;
}

int *getrowsums(int arr[][10], int r, int c)
{
	int i, j, *sum= (int*)malloc(r*sizeof(int));
	for(i=0; i<r; i++)
	    sum[i]= getsum(arr[i], c);
	return sum;
}

int isdiverse(int arr[][10], int r, int c)
{
	int i, j, *sum;
	sum= getrowsums(arr, r, c);
	for(i=0; i<r; i++)
	{
		for(j=0; j<i; j++)
			if(sum[i]==sum[j])
				break;
		if(j<i)
			break;
	}
	return i<r? 0 : 1;
}

void main()
{
	int i, j, r, c, arr[10][10], *sum, sumpos1=0, sumpos2=0;
	printf("Enter the dimensions of the 2-D array:\n");
	printf("Enter the no. of rows: ");
	scanf("%d", &r);
	printf("Enter the no. of columns: ");
	scanf("%d", &c);

	printf("\nEnter the elements for the square array:\n");
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
		{
			printf("Enter element #(%d, %d): ", (i+1), (j+1));
			scanf("%d", &arr[i][j]);
		}
    sum= getrowsums(arr, r, c);
	printf("\n\nGiven array elements\t\t\tRow sums:\n");
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
		{
			if(i!=j && sum[i]==sum[j])
			{
				sumpos1= i+1;
				sumpos2= j+1;
			}
			printf("%d\t", arr[i][j]);
			if(j==c-1)
				printf("\t%d\n", sum[i]);
		}
	
	if(sumpos1!=0)
	   printf("\nRow %d and Row %d are the same!\nThe array is not diverse.\n\n", sumpos1, sumpos2);
	else
		printf("\n\nRow sums are all different!\nThe array is diverse.\n\n");
	getch();
}