#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void search(char month[][2][15], char searchitem[])
{
	int i, j, srchCnt=0;
	char ch, str[100];
	for(i=0; i<12; i++)
	{
		if(strcmpi(searchitem, month[i][0])==0 || 
		strcmp(searchitem, month[i][1])==0 ||
		strcmp(searchitem, itoa(i, str, 10))==0)
		{
			if(++srchCnt == 1)
			    printf("\nSearch successful! The details of the matching record:\n%-6s%-15s%-10s", 
			    	"#", "MONTH NAME", "DAYS");
			printf("\n%-6d%-15s%-10s", (i+1), month[i][0], month[i][1]);
		}
	}
	if(srchCnt==0)
		printf("\nThe search item is not found in the array!");
}

void main()
{
	int i, j;
	char month[12][2][15] = {{"January", "31"}, {"Febuary", "28"}, {"March", "31"}, 
		{"April", "30"}, {"May", "31"}, {"June", "30"}, {"July", "31"}, 
		{"August", "31"}, {"September", "30"}, {"October", "31"}, 
		{"November", "30"}, {"December", "31"}}, srchitem[15];

	printf("\nThe details of the month are:\n");
	printf("\n%-6s%-15s%-10s", "#", "MONTH NAME", "DAYS");
	for(i=0; i<12; i++)
		printf("\n%-6d%-15s%-10s", (i+1), month[i][0], month[i][1]);
	
	printf("\n\nEnter the item for month search: ");
	gets(srchitem);
    
    search(month, srchitem);
    getch();
}