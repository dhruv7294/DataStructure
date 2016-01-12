/*  Write a program to sort an array using Bubble Sort   */

#include<stdio.h>
#include<conio.h>
#define N 6

void disp(int k []);
void bubble_sort(int k[]);

void main()
{
    int k[N],i;
clrscr();
    printf("\nEnter Array Elements ...\n\n ");
    for(i=0;i<N;i++)
    {
      printf("\nEnter k[%d] : ",i);
      scanf("%d",&k[i]);
    }
    clrscr();
    printf("\n======================================");
    printf("\nBefore Sorting:  ");
    disp(k);
    printf("\n======================================\n\n");

    bubble_sort(k);

    printf("\n\n\n====================================");
    printf("\nAfter Sorting:  ");
    disp(k);
    printf("\n====================================\n");

getch();
}
void bubble_sort(int k[])
{
int Last,i,j,temp,count;
   Last=N;
   for(i=0;i<N-1;i++)
   {
    count=0;
     for(j=0;j<Last-1;j++)
     {
       if(k[j]>k[j+1])
       {
	 temp=k[j];
	 k[j]=k[j+1];
	 k[j+1]=temp;
	 count++;
       }
    }
       printf("\nPass : %d\t",i+1);
       disp(k);
       getch();

       if(count==0)
	   return ;
       else
	 Last=Last-1;

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

======================================
Before Sorting:  5  7  2  9  8  1
======================================

Pass : 1        5  2  7  8  1  9
Pass : 2        2  5  7  1  8  9
Pass : 3        2  5  1  7  8  9
Pass : 4        2  1  5  7  8  9
Pass : 5        1  2  5  7  8  9

====================================
After Sorting:  1  2  5  7  8  9
====================================

*/
