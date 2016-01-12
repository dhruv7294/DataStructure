/*	Write a program to perform the following operations
	on an Array. (Insert, Delete, Traverse)         */

#include<stdio.h>
#include<conio.h>
#define SIZE 20

void traverse(int [],int);
int insert(int [],int,int,int);
int del(int [],int,int,int);

void main()
{
 int k[SIZE],pos,item,i,ch,N;
clrscr();
  printf("\nHow many elements you want to insert:");
  scanf("%d",&N);

  printf("\nEnter Array Elements .....\n\n");
  for(i=0;i<N;i++)
  {
    printf("Enter k[%d] : ",i);
    scanf("%d",&k[i]);
  }
  clrscr();
  do
  {
	  clrscr();
	  printf("\n\n1. For Insert");
	  printf("\n2. For Delete");
	  printf("\n3. For Traverse");
	  printf("\n4. For Exit");

	  printf("\n\nEnter your choice:");
	  scanf("%d",&ch);

	  switch(ch)
	  {
	     case 1: printf("\nEnter item to be inserted :");
		     scanf("%d",&item);
		     up:
		     printf("\nEnter pos :");
		     scanf("%d",&pos);
		     if(pos<0 || pos>=N)
		     {
		       printf("\nInvalid position !....");
		       getch();
		       goto up;
		     }
		     N =insert(k,N,pos-1,item);

		     break;

	     case 2: up1:
		     printf("\nEnter pos :");
		     scanf("%d",&pos);
		     if(pos<0 || pos>=N)
		     {
		       printf("\nInvalid position !....");
		       getch();
		       goto up1;
		     }
		     N =del(k,N,pos-1,item);
		     break;

	     case 3: traverse(k,N);
		     getch();
		     break;

	     case 4: exit();
		     break;
	  }

   } while(ch!=4);

getch();
}
void traverse(int k[],int N)
{
  int i;
  printf("\nArray Elements .....\n\n");
  for(i=0;i<N;i++)
  {
    printf(" %d ",k[i]);
  }
}

int insert(int k[],int N,int pos,int item)
{
   int i=N;
   if(N==SIZE)
   {
     printf("\nArray Overflow!....");
     getch();
     return;
   }
   while(i>=pos)
   {
      k[i+1] = k[i];
      i--;
   }
   k[pos] = item;

   N = N + 1;
   return N;
}

int del(int k[],int N,int pos,int item)
{
   int i=pos;
   if(N<0)
   {
     printf("\nArray underflow!....");
     getch();
     return;
   }

   item=k[pos];

   while(i<N)
   {
     k[i]=k[i+1];
     i++;
   }
   N = N -1;
   printf("\n\n%d is deleted !...",item);
   return N;
}

/*	OUTPUT

How many elements you want to insert:5

Enter Array Elements .....

Enter k[0] : 1
Enter k[1] : 2
Enter k[2] : 3
Enter k[3] : 4
Enter k[4] : 5

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:3

Array Elements .....

 1  2  3  4  5

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:1

Enter item to be inserted :100

Enter pos :2

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:3

Array Elements .....

 1  100  2  3  4  5

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:2

Enter pos :3

2 is deleted !...

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:3

Array Elements .....

 1  100  3  4  5

1. For Insert
2. For Delete
3. For Traverse
4. For Exit

Enter your choice:4




*/
