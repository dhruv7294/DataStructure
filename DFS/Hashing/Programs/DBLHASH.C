#include<stdio.h>
#include<conio.h>
#define SIZE 13

void main()
{
 int arr[SIZE]={0},key,ch,i,j,loc,cnt=1,hploc,t=11,hiloc;
clrscr();

// 18 26 35 9 64 47 96 36 70

  while(1)
   {
     printf("\nEnter the key :");
     scanf("%d",&key);

	loc=key%SIZE;

	if(arr[loc]==0)
	{
	   arr[loc]=key;
	}
	else
	{
	   while(1)
	   {
	     hploc=t-(key%t);
	     hiloc=(loc+cnt*hploc)%13;
	     j=hiloc;

	     if(arr[j]==0)
	     {
		  arr[j]=key;
		  break;
	     }
	     else
		cnt++;
	  }

	}

     printf("\nDo you want to insert an element ? (1/0)");
     scanf("%d",&ch);

     if(ch==0)
       break;
   }


   printf("\n\nArray Elements .....\n");
   for(i=0;i<SIZE;i++)
   {

     printf("%d  ",arr[i]);
   }


getch();
}

