/*   Write a program to sort an array using Selection Sort	*/

#include<stdio.h>
#include<conio.h>
#define N 6

void disp(int k []);
void selection_sort(int k[]);

void main()
{
    int k[N],i;
clrscr();
    printf("\nEnter Array Elements ...\n\n ");
    for(i=0;i<N;i++)
    {
      printf("Enter k[%d] : ",i);
      scanf("%d",&k[i]);
    }
    clrscr();
    printf("\n===========================================");
    printf("\nBefore Sorting:  ");
    disp(k);
    printf("\n===========================================\n\n");

    selection_sort(k);

    printf("\n\n=========================================");
    printf("\nAfter Sorting:  ");
    disp(k);
    printf("\n=========================================\n");

getch();
}
void selection_sort(int k[])
{
int minindex,i,j,temp,count;

   for(i=0;i<N;i++)
   {
     minindex=i;
     for(j=i+1;j<N;j++)
     {
       if(k[j]<k[minindex])
       {
	minindex=j;
       }

    }

       if(minindex!=i)
       {
	 temp=k[i];
	 k[i]=k[minindex];
	 k[minindex]=temp;
      }
       printf("\nPass : %d\t",i+1);
       disp(k);
       getch();

   }

}
void disp(int k [])
{
  int i;
  for(i=0;i<N;i++)
  {
    printf("%d  ",k[i]);
  }
}

/*		OUTPUT

=========================================
Before Sorting:  50  10  90  100  30  60
=========================================

Pass : 1        10  50  90  100  30  60
Pass : 2        10  30  90  100  50  60
Pass : 3        10  30  50  100  90  60
Pass : 4        10  30  50  60  90  100
Pass : 5        10  30  50  60  90  100
Pass : 6        10  30  50  60  90  100

=======================================
After Sorting: 10  30  50  60  90  100
=======================================

*/