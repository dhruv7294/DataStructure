/*   Write a program to sort an array using Quick Sort	*/

#include<stdio.h>
#include<conio.h>
#define SIZE 10
void quick_sort(int [],int ,int);
void print_array(int []);

void main()
{
   int k[10] = {70,36,44,12,89,20,58,64,76,52};
   int LB,UB;
clrscr();

	    printf("\n=======================================================");
	    printf("\nBefore Sorting:  ");
	    print_array(k);
	    printf("\n=======================================================\n");

	    quick_sort(k,0,SIZE-1);

	    printf("\n\n=======================================================");
	    printf("\nAfter Sorting:  ");
	    print_array(k);
	    printf("\n=======================================================\n");

getch();
}
void quick_sort(int k[],int LB,int UB)
{
   int i,j,key,temp,flag=1;

   if(LB>UB)
     return ;
     i=LB;
     j=UB+1;
     key=k[LB];

    printf("\nPass:   ");
    print_array(k);

   while(flag)
   {
     i++;
     while(k[i]<key)
     {
	i++;
     }
     j--;
     while(k[j]>key)
     {
	j--;
     }

     if(i<j)
      {
	temp=k[i];
	k[i]=k[j];
	k[j]=temp;
      }
     else
	 flag=0;
   }
   temp=k[j];
   k[j]= k[LB];
   k[LB]=temp;

    quick_sort(k,LB,j-1);
    quick_sort(k,j+1,UB);
}

void print_array(int k[])
{
   int i;
   for(i=0;i<SIZE;i++)
   {
     printf("%d  ",k[i]);
   }
}

/*  		OUTPUT

=======================================================
Before Sorting:  70  36  44  12  89  20  58  64  76  52
=======================================================

Pass:   70  36  44  12  89  20  58  64  76  52
Pass:   64  36  44  12  52  20  58  70  76  89
Pass:   58  36  44  12  52  20  64  70  76  89
Pass:   20  36  44  12  52  58  64  70  76  89
Pass:   12  20  44  36  52  58  64  70  76  89
Pass:   12  20  44  36  52  58  64  70  76  89
Pass:   12  20  36  44  52  58  64  70  76  89
Pass:   12  20  36  44  52  58  64  70  76  89
Pass:   12  20  36  44  52  58  64  70  76  89
Pass:   12  20  36  44  52  58  64  70  76  89

=======================================================
After Sorting:  12  20  36  44  52  58  64  70  76  89
=======================================================
*/