#include<stdio.h>
#include<conio.h>
#define size 5
insert(int q[],int value,int &front, int &rear)
{
    int dec;
    printf("1: from left \n 2:from right \n");
    scanf("%d",&dec);
    switch(dec)
    {
    case 1:
    {
	if(rear==size-1 && front==0)
	{
	printf("overflow");
	return 0;
	}
	else if(front==rear+1)
	{
	printf("overflow");
	return 0;
	}
	if(front==-1)
	{
	rear=0;
	front=0;
	}
	else if(front==0)
	{
	front=size-1;
	}
	else
	{
	front--;
	}

	q[front]=value;
	break;

    }
    case 2:
    {
	if(rear==size-1 && front==0)
	{
	printf("overflow");
	return 0;
	}
	else if(front==rear+1)
	{
	printf("overflow");
	return 0;
	}
	if(front==-1)
	{
	front=rear=0;
	}
	else if(rear==size-1)
	{
	rear=0;
	}
	else
	{
	rear++;
	}
	q[rear]=value;
	break;
      }
    }
}
delet(int &front,int &rear)
{
   if(front==-1)
   {
      printf("underflow");
      return 0;
   }
   if(front==rear)
   {
    front=rear=-1;
    printf("deleted everything");
   }
   if(front==size-1)
   {
      front=0;
   }
   else
   {
   front++;
   }
   return 0;
}
display(int q[],int &front,int &rear)
{
	int i;
	if(front==-1)
	{
	   printf("empty");
	   return 0;
	}
	if(front<=rear)
	{
	for(i=front;i<=rear;i++)
	{
	  printf("%d",q[i]);
	  printf("\t");
	}
	}
	if(front>rear)
	{
	   for(i=0;i<=rear;i++)
	     {
	       printf("%d",q[i]);
	       printf("\t");
	     }
	   for(i=front;i<size;i++)
	     {
		printf("%d",q[i]);
		printf("\t");
	     }
	}

}
void main()
{
   int q[size],n,value;
   int exit=0;
   int front=-1;
   int rear=-1;
   clrscr();
   printf("\n 1:insert \n 2:delete \n 3:display \n 4:exit \n");
   while(exit!=1)
   {
       printf("\nenter n: ");
       scanf("%d",&n);
	 switch(n)
	 {
	     case 1:
	     {
	     printf("\nenter value:");
	     scanf("%d",&value);
	     insert(q,value,front,rear);
	     break;
	     }
	     case 2:
	     {
	     delet(front,rear);
	     break;
	     }
	     case 3:
	     {
	     display(q,front,rear);
	     break;
	     }
	     case 4:
	     {
	       exit=1;
	       break;
	     }
	 }
   }
   getch();
}