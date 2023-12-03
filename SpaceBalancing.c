#include <stdio.h>
#include <ctype.h>
#include <string.h>

void main()
{
    char str[100], newStr[100], ch;
    float perDouble=0;
    int cnt=0, newCnt=0, wordCnt=0, i, doubleCnt=0;

    printf("Enter the string to balance the spacing and count double lettered words:\n");
    gets(str);

    for(i=0; str[i]!='\0'; i++)
    {
        ch= str[i];
        if(isalnum(ch))
        {
            if(tolower(ch) == tolower(newStr[newCnt-1]))
               cnt++;
            newStr[newCnt++]= ch;
        }
        else if(!isalnum(ch) && newCnt!=0 && isalnum(newStr[newCnt-1]))
        {
            if(cnt>0)
            {
                doubleCnt++;
                cnt=0;
            }
            newStr[newCnt++]= ch;
            wordCnt++;
        }
    }
    newStr[newCnt]= '\0';
    perDouble= (doubleCnt*100.0)/wordCnt;
    printf("\n\nOUPUT:\n");
    printf(newStr);
    printf("\nCount of double-lettered words: %d\nPercentage: %.2f\n\n",
           doubleCnt, perDouble);
}
