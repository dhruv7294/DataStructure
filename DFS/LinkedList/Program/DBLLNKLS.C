#include<stdio.h>
#include<conio.h>
struct LinkedList
{
  int data;
  struct LinkedList *next;
  struct LinkedList *prev;
};
typedef struct LinkedList list;
list *head=NULL;
list *Prev,*Next,*Loc;
void create_head(int);
void disp(list *);
list * insert(list *,int);
list * insert_First(list *,int);
list * insert_At_Pos(list *,int);
list * search_by_pos(list *,int);

void main()
{
     int ch,item,c=0,ch1,pos;
     list *p=NULL;

clrscr();
	do
	{
	up:
	clrscr();
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Display");
	printf("\n4. Find");
	printf("\n5. Exit");

	printf("\n\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	   case 1:
		   if (c==0)
		   {
		       printf("\nEnter item to be inserted :");
		       scanf("%d",&item);

		       create_head(item);
		       p=head;
		       c++;
		   }
		   else
		   {
				do
				{
				clrscr();
				printf("\n1. Insert First");
				printf("\n2. Insert Last");
				printf("\n3. Insert At pos");
				printf("\n4. Insert After Key");
				printf("\n5. Insert Before Key");
				printf("\n6. Go back to main menu");

				printf("\n\nEnter your choice:");
				scanf("%d",&ch1);

				switch(ch1)
				{

					case 1: printf("\n\nEnter Item: ");
						scanf("%d",&item);

						head=insert_First(head,item);
						break;

					case 2: printf("\n\nEnter Item: ");
						scanf("%d",&item);

						p=insert(p,item);
						break;
					case 3:
						 printf("\n\nEnter the pos : ");
						 scanf("%d",&pos);

						 p=search_by_pos(head,pos);
						 printf("\n\nEnter Item: ");
						 scanf("%d",&item);
						 if (pos==1)
							 p=insert_At_Pos(head,item);
						 else
							 p=insert_At_Pos(p,item);
						 break;

					case 6: goto up;
						break;
			       }
			 } while (ch1!=6);
		   }
		   break;

	  case 3:  disp(head);
		   getch();
		   break;

	  case 5:  exit();
		   break;
	 }
     } while(ch!=5);


getch();
}
void create_head(int item)
{
  head= (list *)malloc(sizeof(list));
  head->data=item;
  head->next=NULL;
  head->prev=NULL;
}
void disp(list *ptr)
{

  printf("\nElements of the list ... \n\n");
  while(ptr!=NULL)
  {
    printf("Prev : %d\tSelf : %d\tData : %d\tNext : %d\n\n",ptr->prev,ptr,ptr->data,ptr->next);
    ptr=ptr->next;
  }

}
list *insert(list *p,int item)
{
  list *q;
  q= (list *)malloc(sizeof(list));
  q->data=item;
  q->prev=p;
  q->next=NULL;
  p->next=q;
  return q;
}

list *insert_First(list *p,int item)
{
  list *q;
  q= (list *)malloc(sizeof(list));
  q->data=item;
  q->prev=NULL;
  q->next=p;
  p->prev=q;
  return q;
}
list * insert_At_Pos(list *p,int item)
{
  list *q;

  q=(list *)malloc(sizeof(list));
  q->data=item;
  q->next=p;
  q->prev=Prev;
  p->prev=q;
  return q;
}
list * search_by_pos(list *p,int pos)
{
  int i;
  for(i=0;i<pos-1;i++)
  {
    Prev=p;
    p=p->next;
  }
  Loc=p;
  Next=p->next;
  return Loc;
}

