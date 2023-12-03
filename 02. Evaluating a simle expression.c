#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

float getresult(float n1, float n2, char opr)
{
	switch(opr)
	{
		case '+': return n1+n2;
		case '-': return n1-n2;
		case '*': return n1*n2;
		case '/': return n1/n2;
		case '^': return pow(n1, n2); 
		case '%': return fmod(n1,n2); //since the % operator does not work with fractional nos.
	}
	return -999;
}

int main()
{
	char expn[50], numstr[20], ch, opr;
	float result, oprnd1=0, oprnd2=0;
	int i, cnt=0, dotcnt=0;

	printf("\nEnter an expression to evaluate: ");
	gets(expn);
	
	for(i=0; expn[i]!='\0'; i++)
	{
		ch= expn[i];
		if(isspace(ch))
			continue;
		if(isdigit(ch) || ch=='.')
			numstr[cnt++] = ch;
		else if(ch=='+' || ch=='*' || ch=='-' || ch=='/' || ch=='^' || ch=='%')
		{
			opr= ch;
			numstr[cnt]= '\0';
			oprnd1= atof(numstr);
			cnt= dotcnt= 0;
		}
		else
			break;
	}

	if(expn[i] != '\0')
		printf("\nInvalid expression entered!");
	else
	{
		numstr[cnt]= '\0';
		oprnd2= atof(numstr);
		result= getresult(oprnd1, oprnd2, opr);
		printf("\nOutput:\nResult: %.2f", result);
	}
	getch();
	return 1;
}
