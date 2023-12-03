#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
	char title[50], author[50], publisher[50];
	int refno;
} Book;

void add_books(Book books[], int *n)
{
	int i, nn;
	printf("\nEnter the no. of books to add: ");
	scanf("%d", &nn);
	for(i=*n; i<*n+nn; i++)
	{
		printf("\nEnter details of book #%d:", (i-*n+1));
		printf("\nEnter title: "); 
		getchar(); gets(books[i].title); 
		printf("Enter author: ");
		gets(books[i].author);
		printf("Enter publisher: ");
		gets(books[i].publisher);
		printf("Enter reference number: ");
		scanf("%d", &books[i].refno);
	}
	*n+= nn;
}

void show_books(Book books[], int n)
{
	printf("\nDetails of the books given below:\n#\t\tTITLE\t\tAUTHOR\t\t\tPUBLISHER\t\tREFERENCE NO.");
	for(int i=0; i<n; i++)
	    printf("\n%d\t\t%s\t\t%s\t\t%s\t\t%d", (i+1), books[i].title, books[i].author, 
	    	books[i].publisher, books[i].refno);
}

void query_books(Book books[], int n, char search_item[])
{
	char str[100];
	int i;
	for(i=0; i<n; i++)
	{
		if(strcmpi(search_item, books[i].title)==0 || 
		strcmp(search_item, books[i].author)==0 ||
		strcmp(search_item, itoa(books[i].refno, str, 10))==0)
        {
        	printf("\nDetails of the books given below:\nTITLE\t\tAUTHOR\t\t\tPUBLISHER\t\tREFERENCE NO.");
        	printf("\n%s\t\t%s\t\t%s\t\t%d", books[i].title, books[i].author, 
	    	books[i].publisher, books[i].refno);
	    	break;
        }
	}
	if(i==n)
		printf("\nThe search item is NOT found in the array!");
}

void main()
{
	Book books[10];
	char srchitem[50];
	int n=0, ch;

	do
	{
		printf("\nBOOK MENU OPTIONS:");
	   printf("\n01. Add Books");
	   printf("\n02. Show Books");
		printf("\n03. Show query"); 
	   printf("\n04. Exit program");
      printf("\nEnter your choice(1 - 4): ");
      scanf("%d", &ch);

     	switch(ch)
     	{
           case 1:
           add_books(books, &n);
           break;

           case 2:
           show_books(books, n);
           break;

           case 3:
           printf("\nEnter the search item: ");
           getchar(); gets(srchitem);
           query_books(books, n, srchitem);
           break;

           case 4:
           printf("\nThe program ends here. Thank you for using it!\n");
           break;

           default:
           printf("\nInvalid choice entered! Please try again.\n");
           break;
        }
	} while(ch!=4);
	getch();
}