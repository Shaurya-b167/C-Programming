#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int isendofsent(char str[], char ch, int i)
{
	if(str[i+1]=='\0')
		return 1;
	if((ch=='.' || ch=='?' || ch=='!') && str[i+1]==' ' && isupper(str[i+2]))
		return 1;
	return 0;
}

void showVowelRichWords(char sent[])
{
	char wrd[20], ch, chr;
	int i, sentCnt=0, wrdCnt=0, vowelCnt=0, cnt=0;

	for(i=0; sent[i]!='\0'; i++)
	{
		ch= sent[i];
		if(isalpha(ch))
		{
			chr= tolower(ch);
			if(chr=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
				vowelCnt++;
			wrd[wrdCnt++]= ch;
		}
		else if(wrdCnt!=0)
		{
			wrd[wrdCnt]= '\0';
			if(vowelCnt>=2)
			{
				if(cnt++ == 0)
					printf("\nThe vowel-rich words are:\n");
				printf("%s, ", wrd);
			}
			wrdCnt= vowelCnt= 0;
		}
	} 
	if(cnt==0)
		printf("\nThere are no vowel rich words in the sentence!");
}

void main()
{
	char str[300], sent[100], ch;
	int i, sentCnt=0, cnt=0;

	printf("Enter a sentence to find the vowel rich words:\n");
    gets(str);

    printf("\n\nOUTPUT:\n");
	for(i=0; str[i]!='\0'; i++)
	{
		ch= str[i];
		sent[sentCnt++]=ch;
		if(isendofsent(str, ch, i)==1)
		{
			sent[sentCnt]= '\0';
			printf("\n%d\t%s", ++cnt, sent);
			showVowelRichWords(sent);
			sentCnt=0;
		}
	}
	getch();
}