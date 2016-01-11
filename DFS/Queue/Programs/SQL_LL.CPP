// Queue using Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
struct QueueList
{
  int data;
  struct QueueList *next;
};
typedef struct QueueList Queue;
Queue *F=NULL,*R=NULL;
void insert(int);
void del();
void disp();

void main()
{
 int ch;
 int item;
clrscr();

		do
		{
		  clrscr();
		  printf("\n 1 for Insert");
		  printf("\n 2 for Delete");
		  printf("\n 3 for Display");
		  printf("\n 4 for Exit");
		  printf("\n\t Enter choice:");
		  scanf("%d", &ch);

		    switch(ch)
		    {
		      case 1 : printf("\n\t Enter item for insertion:");
			       scanf("%d", &item);
			       insert(item);
			       break;

		      case 2 : del();
			       break;

		      case 3 : disp();
			       break;

		      case 4 : printf("\n\t Thanks...!");
			       getch();
			       exit(0);
			       break;

		      default : printf("\n\t Wrong choice...!");
				getch();
				break;
		    }
		}while(ch!=4);
getch();
}

void insert(int item)
{
  Queue *q;
  q=(Queue *)malloc(sizeof(Queue));
  q->data=item;
  q->next=NULL;

  if(F==NULL || R==NULL)
  {
     F=q;
     R=q;
  }
  else
  {
    R->next=q;
    R=q;
  }

}
void del()
{
  Queue *q;
  int item;

  if(F==NULL || R==NULL)
  {
     printf("\n\nQueue Underflow!.....");
     getch();
     return;
  }
  else
  {
     q=F;
     item=q->data;
     F=F->next;
     free(q);
  }
}
void disp()
{
  Queue *q;

  if(F==NULL || R==NULL)
  {
     printf("\n\nQueue is Empty !....");
     getch();
     return;
  }

  q=F;
  while(q!=NULL)
  {
     printf(" %d ",q->data);
     q=q->next;
  }
      getch();
}