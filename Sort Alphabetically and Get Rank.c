#include <stdio.h>
#include <string.h>
#include <conio.h>

void sortrecords(char name[][], float avgmarks[], int n)
{
	char s[100];
	int i, j, avgCnt=0, cnt=0, nameCnt=0;
	for(i=0; i<n; i++)
		for(j=0; j<n-i-1; j++)
		{
			for(k=0; name[j][k]!='\0' && name[j+1][k]!='\0'; k++)
			{
				if((int)name[j][k] > (int)arr[j+1][k])
				{
					strcpy(s, name[j]);
					strcpy(name[j], name[j+1]);
					strcpy(name[j+1], s);
					avgmarks[j]= avgmarks[j] + avgmarks[j+1] - (avgmarks[j+1]= avgmarks[j]);
				}
				if((int)name[j][k]!=(int)name[j+1][k])
					break;
			}
		}
}

int getrank(float avgmarks[], int pos, int n)
{
	int i;
	for(i=0; i<n; i++)
}