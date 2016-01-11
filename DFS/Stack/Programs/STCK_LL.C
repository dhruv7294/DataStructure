// Stack Operations using Linked List

#include<stdio.h>
#include<conio.h>
#define SIZE 10
struct StackList
{
  int data;
  struct StackList *next;
};
typedef struct StackList stack;
stack *top=NULL;
int cnt=0;

void push(int);
void pop();
void peep(int);
void disp();
void change(int ,int);

void main()
{
 int ch,item,pos;
clrscr();
  do
  {
  clrscr();
  printf("\n\n1. Push");
  printf("\n2. Pop");
  printf("\n3. Peep");
  printf("\n4. change");
  printf("\n5. Disp");
  printf("\n6. Exit");

  printf("\n\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
	case 1:
		  printf("\nEnter Item:");
		  scanf("%d",&item);

		  push(item);
		  break;
	case 2:
		  pop();
		  break;
	case 3:
		  printf("\nEnter the pos:");
		  scanf("%d",&pos);

		  peep(pos);
		  break;
	case 4:
		  printf("\nEnter the pos:");
		  scanf("%d",&pos);

		  printf("\nEnter the item:");
		  scanf("%d",&item);

		  change(pos,item);
		  break;

	case 5:
		  disp();
		  break;
	case 6:
		  exit(0);
		  break;

    }

 } while(ch!=6);

getch();
}

void push(int item)
{
  stack *q;
  q=(stack *)malloc(sizeof(stack));
  q->data=item;
  q->next=top;
  top=q;
  printf("\n\n%d is pushed !....",item);
  cnt++;
  printf("\n\nNo of items :%d",cnt);

  getch();
}
void disp()
{
   stack *ptr=top;
   if(top==NULL)
   {
     printf("\n\nStack is empty !.....");
     getch();
     return;
   }

   printf("\n\nStack Elements !.....\n\n");
   while(ptr!=NULL)
   {
      printf("\n%d",ptr->data);
      ptr=ptr->next;
   }
   getch();
}

void pop()
{
   stack *q;

   if(top==NULL)
   {
     printf("\n\nStack underflow !.....");
     getch();
     return;
   }
   q=top;
   printf("\n\n%d is popped !...",top->data);
   top=top->next;
   free(q);
   getch();
}


void peep(int pos)
{
  int i=0;
  stack *ptr=top;
  if(pos<=0 || pos>cnt)
  {
     printf("\n\nInvalid position !.....");
     getch();
     return;

  }

  while(i<pos-1)
  {
    ptr=ptr->next;
    i++;
  }
  printf("\n\n%d is found at pos %d ",ptr->data,i+1);
  getch();

}
void change(int pos,int item)
{
  int i=0;
  stack *ptr=top;
  if(pos<=0 || pos>cnt)
  {
     printf("\n\nInvalid position !.....");
     getch();
     return;

  }

  while(i<pos-1)
  {
    ptr=ptr->next;
    i++;
  }
  printf("\n\n%d is replaced by %d ",ptr->data,item);
  ptr->data=item;
  getch();

}


