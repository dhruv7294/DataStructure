#include<stdio.h>
#include<conio.h>
#define N 10

void disp(int k []);
void simple_merge_sort(int k[],int,int,int);

void main()
{
    int k[N],i,LB,MID,UB;
clrscr();
    printf("\nEnter Array Elements ...\n\n ");
    for(i=0;i<N;i++)
    {
      printf("Enter k[%d] : ",i);
      scanf("%d",&k[i]);
    }
    clrscr();
    printf("\n=========================================");
    printf("\nBefore Sorting:\n\n");
    disp(k);
    printf("\n========================================\n\n");

    LB=0;
    UB=N;
    MID=(LB+UB)/2;
    simple_merge_sort(k,LB,MID,UB);

    printf("\n\n\n=========================================");
    printf("\nAfter Sorting:\n\n");
    disp(k);
    printf("\n=======================================\n");

getch();
}
void simple_merge_sort(int k[],int first,int sec,int third)
{
int i,j,l,temp[N];
       i=first;
       j=sec;
       l=-1;
       while(i<sec && j <third)
       {
	 if(k[i]<=k[j])
	 {
	   l++;
	   temp[l]=k[i];
	   i++;
	 }
	 else
	 {
	   l++;
	   temp[l]=k[j];
	   j++;
	 }
      } // End of while

	 if(i>sec)
	 {
	   while(j<third)
	   {
	     l++;
	     temp[l]=k[j];
	     j++;
	   }
	  }
	  else
	  {
	     while(i<sec)
	     {
	     l++;
	     temp[l]=k[i];
	     i++;
	     }
	  }

		  // Copy Back your data into original array
		  for(i=0; i<=l; i++)
		  {
		    k[first+i] = temp[i];
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
========================================
Before Sorting:
10  20  30  40  50  11  22  33  44  55
========================================

=======================================
After Sorting:
10  11  20  22  30  33  40  44  50  55
=======================================
*/