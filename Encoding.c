#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{
    char str[100], newStr[100], ch;
    int i, n, cnt=0, val;

    printf("Text:\n");
    gets(str);
    printf("Shift value: ");
    scanf("%d", &n);

    for(i=0; str[i]!='\0'; i++)
    {
        ch= str[i];
        val= (int)ch;
        if(isalnum(ch))
            newStr[cnt++]= val>90-n && val<=90? (char)(n-(90-val+1)+65) :
                           val>122-n && val<=122?(char)(n-(122-val+1)+97) :
                        val>57-n && val<=57? (char)(n - (57-val+1)+48) : (char)(ch+n);
        else
            newStr[cnt++]= ch;
    }
    newStr[cnt]= '\0';
    printf("\n\nOUPUT:\n%s\n\n", newStr);
}
//Attack the ZEBRAS, at the Zebra Line, at 9:09 pm.
