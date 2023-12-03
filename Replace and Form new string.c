#include <stdio.h>
#include <ctype.h>
#include <string.h>

void getreplaced(char srchwrd[], char repwrd[], char str[])
{
    char newStr[100], wrd[30], ch;
    int i, newCnt=0, wrdCnt=0, repCnt=0, cnt=0, j, k, startPos;
    for(i=0; str[i]!='\0'; i++)
    {
        ch= str[i];
        if(isalnum(ch))
            wrd[wrdCnt++]= ch;
        else if(wrdCnt!=0)
        {
            repCnt=0;
            for(j=0; j<wrdCnt; j++)
            {
                cnt=0;
                for(k=j; k<wrdCnt; k++)
                {
                    if(cnt!=-1 && tolower(wrd[k])==tolower(srchwrd[cnt]))
                    {
                        if(cnt==0)
                           startPos=k;
                        newStr[newCnt++]= repwrd[repCnt++];
                        cnt++;
                    }
                    else if(cnt==-1)
                        newStr[newCnt++]= wrd[k];
                    else
                        if(srchwrd[cnt]=='\0')
                           if(repwrd[repCnt]!='\0')
                           {
                               newStr[newCnt++]= repwrd[repCnt++];
                               k--;
                               if(repwrd[repCnt]=='\0')
                                  newStr[newCnt++]= wrd[k+1];
                           }
                           else if(k-startPos==cnt)
                               cnt=-1;
                           else
                           {
                            newCnt= newCnt-cnt;
                            repCnt=0;
                            cnt=0;
                           }
                }
                if(cnt==0)
                    newStr[newCnt++]= wrd[j];
                else if(cnt==-1)
                    break;
            }
            newStr[newCnt++]=ch;
            wrdCnt=0;
        }
        else
            newStr[newCnt++]=ch;
    }
    printf("\n\nOUTPUT:\n%s", newStr);
}

void main()
{
    char str[100], srchwrd[20], repwrd[20];
    printf("Enter the sentence:\n");
    gets(str);
    printf("Substring to search for: ");
    gets(srchwrd);
    printf("Substring to replace with: ");
    gets(repwrd);

    getreplaced(srchwrd, repwrd, str);
}
//While resting in a restaurant, I got arrested.
