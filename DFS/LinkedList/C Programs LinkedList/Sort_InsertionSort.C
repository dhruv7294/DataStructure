/*	Write a program to sort an array using Insertion Sort   */

#include<stdio.h>
#include<conio.h>

void InsertionSort(int k[],int n);

void PrintArray(int k[],int n);

void main()
{
int i,n=7;
int k[7];
clrscr();
	      for(i=0; i<n; i++)
	      {
	       printf("\n Enter k[%d]:", i+1);
	       scanf("%d", &k[i]);
	      }
	       clrscr();
	    printf("\n================================================");
	    printf("\nBefore Sorting:  ");
	    PrintArray(k,n);
	    printf("\n================================================\n");

	    InsertionSort(k,n);

	    printf("\n\n===============================================");
	    printf("\nAfter Sorting:  ");
	    PrintArray(k,n);
	    printf("\n===============================================\n");

getch();
}

void InsertionSort(int k[],int n)
{
  int i, ptr, temp;

		for(i=1; i<n; i++)
		{
		   temp = k[i];
		   ptr=i-1;
		   printf("\nPass : %d   ",i);
		   PrintArray(k,n);
		   getch();

		   while(ptr>-1 && k[ptr] > temp)
		     {
			k[ptr+1] = k[ptr];
			ptr--;
		     }
		  k[ptr+1] = temp;
		}
}


void PrintArray(int k[],int n)
{
 int i;
	for(i=0;i<n;i++)
	{
	 printf("%3d ",k[i]);
	}
}
/* 		OUTPUT

================================================
Before Sorting:   90  20  50 100  60 150  10
================================================

Pass : 1    90  20  50 100  60 150  10
Pass : 2    20  90  50 100  60 150  10
Pass : 3    20  50  90 100  60 150  10
Pass : 4    20  50  90 100  60 150  10
Pass : 5    20  50  60  90 100 150  10
Pass : 6    20  50  60  90 100 150  10

===============================================
After Sorting:   10  20  50  60  90 100 150
===============================================

*/

                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

