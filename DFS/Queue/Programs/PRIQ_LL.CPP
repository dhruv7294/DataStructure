// Priority Queue using Linked List

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct PriorityQueue
{
  	int data;
	  int priority;
	  struct PriorityQueue *next;
};
typedef struct PriorityQueue PQ;
PQ *F=NULL;
int N=0; // Total no of nodes in a list

void insert(int ,int);
void disp();
void del();

void main()
{
 int ch,item,pr;

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

		     insert(item,pr);
		     getch();
		     break;

	     case 2: del();
		     getch();
		     break;

	     case 3: disp();
		     getch();
		     break;

	     case 4: exit(0);
		     break;
	  }

   } while(ch!=4);

getch();
}

void insert(int item,int pri)
{
	PQ *q,*ptr,*prev;

  	q=(PQ *) malloc(sizeof(PQ));
	q->data=item;
	q->priority=pri;
  
	// first node
	  if(F==NULL)
	  {
		    q->next=NULL;
		    F=q;
	  }
	  // if smallest priority comes
	  else if(pri<F->priority)
	  {
		     q->next=F;
		     F=q;
	  }
	  // insert node in middle
	  else
	  {
		    ptr=F;
		    while(ptr!=NULL)
		    {
			      if(ptr->priority>pri)
				break;
			      prev=ptr;
			      ptr=ptr->next;
		    }
		    prev->next=q;
		    q->next=ptr;
	  }

	  printf("\n\n%d is inserted !....",item);
	  N++;
	  printf("\n\nTotal Elements : %d",N);

}

void disp()
{
	  PQ *ptr=F;
	  if(F==NULL)
	  {
		     printf("\n\nPriority Queue is empty !......");
		     return;
	  }
	  while(ptr!=NULL)
	  {
		     printf("\n Data : %d\t Prio : %d",ptr->data,ptr->priority);
		     ptr=ptr->next;
	  }
}

void del()
{
	  PQ *q;

	  if(F==NULL)
	  {
		     printf("\n\nPriority Queue Underflow !......");
		     return;
	  }

	  q=F;
	  printf("\n\n%d is deleted !....",F->data);
	  F=F->next;
	  free(q);

	  printf("\n\nTotal Elements : %d",N);
}
