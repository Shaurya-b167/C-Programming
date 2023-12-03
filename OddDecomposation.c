#include <stdio.h>

void odd_decompose(int num)
{
    int i, cnt=0;
    for(i=3; i<num/i; i+=2)
       if(num%i==0)
       {
           if(cnt==0)
               printf("\n\nODD DECOMPOSATION FOR %d: ", num);
           printf("\n%d x %d", i, num/i);
           cnt++;
       }
    if(cnt==0)
        printf("\n\nThe given number is NOT composed of two odd numbers!\n\n");
    else
        printf("\n\n");
}

void main()
{
    int n;
    printf("\nEnter an integer for odd decomposation: ");
    scanf("%d", &n);
    odd_decompose(n);
}
