#include<stdio.h>

int isPrime(int n)
{
    if(n<2)
        return 0;
    for(int i=2; i<=n/2; i++)
        if(n%i==0)
           return 0;
    return 1;
}

void main()
{
    int i, n, nextPrime=0, prevPrime=0;
    printf("Enter a number to compute the next and previous prime numbers: ");
    scanf("%d", &n);

    if(n<=2)
        prevPrime=-999;
    for(i=1; nextPrime==0 || prevPrime==0; i++)
    {
        if(nextPrime==0 && isPrime(n+i))
            nextPrime= n+i;
        if(prevPrime==0 && isPrime(n-i))
            prevPrime= n-i;
    }

    printf("\n\nNext prime after %d is %d", n, nextPrime);
    if(prevPrime==-999)
       printf("\nNo previous prime exists before %d\n\n", n);
    else
        printf("\nPrevious prime before %d is %d\n\n", n, prevPrime);
}
