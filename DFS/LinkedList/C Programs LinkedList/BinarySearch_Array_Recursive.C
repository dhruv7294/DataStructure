/*   Write a program to perform Recursive Binary Search on an array   */

#include<stdio.h>
#include<conio.h>
#define SIZE 8

int binary_search(int k[],int,int,int);
void main()
{
	int k[SIZE],i,item,isFound;
	int low=0,high=SIZE-1;
clrscr();
	printf("\nEnter the array Elements in sorted order ...\n\n");
	for(i=0;i<SIZE;i++)
	{
	 printf("Enter k[%d] : ",i);
	 scanf("%d",&k[i]);
	}
	clrscr();
	printf("\n\nArray Elements... \n\n ");
	for(i=0;i<SIZE;i++)
	{
		printf("%d  ",k[i]);
	}

	printf("\n\nEnter the item to be searched : ");
	scanf("%d",&item);

	isFound=binary_search(k,item,low,high);

	if(isFound!=-1)
	{
	  printf("\nSuccessful search .... ");
	  printf("\n\n%d is found at pos %d ",item,isFound+1);
	}
	else
	{
	  printf("\nUnsuccessful search .... ");
	}

getch();
}
int binary_search(int k[],int item,int low,int high)
{
int pos,mid;
		if (low>high)
		{
		 return -1;
		}
		mid=(low+high)/2;
		if(item<k[mid])
		{
		   high=mid-1;
		   binary_search(k,item,low,high);
		}
		else if(item>k[mid])
		{
		   low=mid+1;
		   binary_search(k,item,low,high);
		}
		else
		{
		   return mid;
		}


}

/*	 	OUTPUT

Array Elements...

 10  20  30  40  50  60  70  80

Enter the item to be searched : 20

Successful search ....

20 is found at pos 2

*/



                                                                                
                                                                                
