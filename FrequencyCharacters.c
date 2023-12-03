#include <stdio.h>
#include <ctype.h>

void main()
{
    char str[100], ch;
    int lowerFreq=0, upperFreq=0, digFreq=0, specFreq=0, wordFreq=0, wordLen=0;

    printf("Enter the string to compute the frequency of different characters:\n");
    gets(str);

    for(int i=0; str[i]!='\0'; i++)
    {
        ch= str[i];
        if(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            upperFreq++;
        else if(islower(ch) && ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
            lowerFreq++;
        else if(ch>='0' && ch<='9')
            digFreq++;
        if(isalnum(ch))
            wordLen++;
        else if(ch<'0' || ch>'9')
        {
            if(wordLen>3)
                wordFreq++;
            if(ch!=' ')
                specFreq++;
            wordLen=0;
        }
    }

    printf("\n\nThe frequency of characters in the given string: ");
    printf("\nUppercase vowels: %d\nLowercase consonants: %d", upperFreq, lowerFreq);
    printf("\nSpecial character(excluding spaces): %d", specFreq);
    printf("\nDigits: %d\nWords(with length > 3): %d\n\n", digFreq, wordFreq);
}
