// Priority Queue using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10

int insert(int PQ[2][SIZE],int , int ,int);
int find(int PQ[2][SIZE],int,int );
void traverse(int PQ[2][SIZE],int);
int  del(int PQ[2][SIZE],int);

void main()
{
 int PQ[2][SIZE],pr,item,i,ch,N=0;
clrscr();
  do
  {
	  clrscr();
	  printf("\n1. For Insert");
	  printf("\n2. For Delete");
	  printf("\n3. For Traverse");
	  printf("\n4. For Exit");

	  printf("\nEnter your choice:");
	  scanf("%d",&ch);

	  switch(ch)
	  {
	     case 1:
		     printf("\n\nEnter priority :");
		     scanf("%d",&pr);

		     printf("\nEnter item to be inserted :");
		     scanf("%d",&item);

		     N=insert(PQ,N,pr,item);

		     break;

	     case 2: N=del(PQ,N);
		     break;

	     case 3: traverse(PQ,N);
		     getch();
		     break;

	     case 4: exit(0);
		     break;
	  }

   } while(ch!=4);

getch();
}
void traverse(int PQ[2][SIZE],int N)
{
  int i,j;
  printf("\nArray Elements .....\n\n");

  for(i=0;i<N;i++)
  {
      printf("\n %d ",PQ[0][i]);
      printf(" %d ",PQ[1][i]);
  }

}

int insert(int PQ[2][SIZE],int N,int pr,int item)
{
   int i,j,pos;

   if(N==SIZE)
   {
     printf("\nQueue Overflow!....");
     getch();
     return 0;
   }
   pos=find(PQ,N,pr);

   if(pos==N)
   {
     PQ[0][N]=item;
     PQ[1][N]=pr;
   }
   else
   {
    for(i=N-1;i>=pos;i--)
    {
      PQ[0][i+1]= PQ[0][i];
      PQ[1][i+1]= PQ[1][i];
    }
    PQ[0][pos]=item;
    PQ[1][pos]=pr;
   }

   N = N + 1;
   return N;
}

int del(int PQ[2][SIZE],int N)
{
   int F=-1,i=0,item;
   if(F==N)
   {
     printf("\nQueue underflow!....");
     getch();
     return 0;
   }
   else
   {
    F++;
    item=PQ[0][F];

    while(i<N)
    {
     PQ[0][i]=PQ[0][i+1];
     PQ[1][i]=PQ[1][i+1];
     i++;
    }
    N = N -1;
    printf("\n\n%d is deleted !...",item);
    getch();
    return N;
   }
}


int find(int PQ[2][SIZE],int N,int pr)
{
  int i=0;

  for(i=0;i<N;i++)
  {
       if(PQ[1][i]>pr)
       {
	  return i;
       }
  }
  return i;
}
