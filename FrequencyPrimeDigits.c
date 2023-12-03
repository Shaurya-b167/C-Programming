#include <stdio.h>

void main()
{
    char *arr[]= {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
             "Eight", "Nine"};
    int n, cn, i, freq=0, dig;
    printf("Enter an integer to count the frequency of prime digits: ");
    scanf("%d", &n);
    cn=n;

    while(cn>0)
    {
        dig=cn%10;
        for(i=2; i<=dig/2; i++)
            if(dig%i==0)
                break;
        if(dig>1 && i>dig/2)
            freq++;
        cn/=10;
    }
    printf("\nPrime count(in words) for %d: %s\n\n", n, arr[freq]);
}
