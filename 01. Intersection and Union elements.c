#include <stdio.h>
#include <conio.h>

int ispresent(int ele, int arr[], int n)
{
	for(int i=0; i<n; i++)
		if(ele==arr[i])
			return 1;
	return 0;
}

void intersectionset(int arr1[], int n1, int arr2[], int n2)
{
	int i, inter[100], cnt=0;
	for(i=0; i<n1; i++)
		if(ispresent(arr1[i], arr2, n2)==1 && ispresent(arr1[i], inter, cnt))
		      inter[cnt++]= arr1[i];
	if(cnt==0)
		printf("\n\nThere are no intersection elements present!");
	else
	{
		printf("\nThe intersection set:\n");
		for(i=0; i<cnt; i++)
			printf("%d, ", arr1[i]);
	}
}

void unionset(int arr1[], int n1, int arr2[], int n2)
{
	int uni[100], i, cnt= 0;
	for(i=0; i<n1+n2; i++)
	{
		if(i<n1)
			if(ispresent(arr1[i], uni, cnt)==0)
				uni[cnt++]= arr1[i];
		else
			if(ispresent(arr2[i-n1], uni, cnt)==0)
				uni[cnt++]= arr2[i-n1];
	}
	printf("\n\nThe union set:\n");
	for(i=0; i<cnt; i++)
        printf("%d, ", uni[i]);
}

void main()
{
	int arr1[100], n1, arr2[100], n2;
	printf("Enter the size of the first array: ");
	scanf("%d", &n1);
	printf("Enter the size of the second array: ");
	scanf("%d", &n2);

	printf("\nEnter elements for the first array:\n");
	for(int i=0; i<n1; i++)
	{
		printf("Enter element #%d: ", (i+1));
        scanf("%d", &arr1[i]);
	}
	printf("\nEnter elements for the second array:\n");
	for(int i=0; i<n2; i++)
	{
		printf("Enter element #%d: ", (i+1));
        scanf("%d", &arr2[i]);
	}

	intersectionset(arr1, n1, arr2, n2);
	unionset(arr1, n1, arr2, n2);

	getch();
}