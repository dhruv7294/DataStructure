/*   Write a program to perform Linear Search on an array   */

#include<stdio.h>
#include<conio.h>
#define SIZE 8

int linear_search(int [],int);
void main()
{
	int k[SIZE],i,item,j,isFound;
clrscr();
	printf("\nEnter the array Elements:\n\n");
	for(i=0;i<SIZE;i++)
	{
	 printf("Enter k[%d] : ",i);
	 scanf("%d",&k[i]);
	}
	clrscr();
	printf("\n\nArray Elements ...\n\n");
	for(i=0;i<SIZE;i++)
	{
	 printf(" %d ",k[i]);
	}

	printf("\n\nEnter the item to be searched : ");
	scanf("%d",&item);

	isFound =linear_search(k,item);
	if (isFound==-1)
	{
		printf("\n\nUnsuccessful search !....");
	}
	else
	{
		printf("\n\nSuccessful search !....");
		printf("\n\n%d is found at pos %d ",item,isFound+1);
	}

getch();
}
int linear_search(int k[],int item)
{
int i;
	k[SIZE]=item;
	for(i=0;i<SIZE;i++)
	{
	  if(k[i]==item)
	  {
	     return i;
	  }
       }
       return -1;

}

/*	 OUTPUT

Array Elements ...

 1  2  3  4  5  6  7  8

Enter the item to be searched : 3

Successful search !....

3 is found at pos 3

*/





