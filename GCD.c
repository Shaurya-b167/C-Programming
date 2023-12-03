#include <stdio.h>

void main()
{
    int a, b, rem=0;
    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);

    a= a>b? a : a + b - (b = a);
    do
    {
        rem= a%b;
        a= b;
        b= rem;
    }while(rem>0);

    printf("\n\nGCD of the 2 numbers: %d\n\n", a);
}
