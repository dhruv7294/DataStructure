#include<stdio.h>
#include<conio.h>
struct LinkedList
{
  int data;
  struct LinkedList *next;
};

typedef struct LinkedList copy;
typedef struct LinkedList list;


list *head,*Prev;
list *l1=NULL,*l2=NULL;

void create_head(int);
void disp(list *);
list * insert(list *,int);
list * find(list *,int);
void del(list *);
int count(list *);
int sum(list *);
void copylist(list *);
list* reverse(list*);
list* merge();
void getTwoList();

void main()
{
   int ch,ch1,pos,item,c=0,cnt,ans;

   list *p,*loc,*t;

clrscr();

	do
	{
	up:
	clrscr();
	printf("\n1. Insert an Element");
	printf("\n2. Delete an Element");
	printf("\n3. Traverse the linked list");
	printf("\n4. Search the element");
	printf("\n5. Count the no of nodes");
	printf("\n6. Find the sum Of Elements");
	printf("\n7. Copy the linked list");
	printf("\n8. Reverse the linked list");
	printf("\n9. Merge two linked list");
	printf("\n10.Union of two linked list");
	printf("\n11.Intersection of two linked list");
	printf("\n12.Exit");

	printf("\n\nEnter your choice:");
	scanf("%d",&ch);

	switch(ch)
	{
	   case 1:
		  printf("\nEnter item to be inserted :");
		  scanf("%d",&item);

		   if (c==0)
		   {

		       create_head(item);
		       p=head;
		       c++;
		   }
		   else
		   {
			p=insert(p,item);
		   }
		   break;

	  case 2:  printf("\nEnter item to be deleted:");
		   scanf("%d",&item);

		   loc=find(head,item);
		   del(loc);
		   printf("\n%d is deleted ...", item);

		   getch();
		   break;

	   case 3: disp(head);
		   getch();
		   break;

	   case 4:
		   printf("\nEnter item to be searched :");
		   scanf("%d",&item);

		   loc=find(head,item);
		   printf("\n%d is found at location %d",item,loc);

		   getch();
		   break;

	  case 5:  cnt = count(head);
		   printf("\n\nTotal no of nodes : %d ",cnt);
		   getch();
		   break;

	  case 6: ans=sum(head);
		  printf("\n\nSum of elements: %d ",ans);
		  getch();
		  break;

	  case 7: copylist(head);
		  getch();
		  break;

	  case 8:t=reverse(head);
		 disp(t);
		 getch();
		 break;

	  case 9:
		 getTwoList();
		 t=merge();
		 disp(t);
		 getch();
		 break;


	  case 12:exit(0);

	}

    } while(ch!=12) ;



getch();

}

void create_head(int item)
{
  head= (list *)malloc(sizeof(list));
  head->data=item;
  head->next=NULL;
}
void disp(list *ptr)
{

  printf("\nElements of the list ... \n\n");
  do
  {
    printf("\nSelf : %d\tData : %d\tNext : %d",ptr,ptr->data,ptr->next);
    ptr=ptr->next;
  } while(ptr!=head);

}
list *insert(list *p,int item)
{
  list *q;
  q= (list *)malloc(sizeof(list));
  q->data=item;
  q->next=head;
  p->next=q;
  return q;
}

list * find(list *ptr,int item)
{
	do
	{
		if (item==ptr->data)
		{
			return ptr;

		}
		Prev=ptr;
		ptr=ptr->next;

	} while(ptr!=head);

	 return NULL;
}
void del(list *ptr)
{
   if (ptr==head)
   {
       list *p=head;
       head=ptr->next;
       do
       {
	 p=p->next;

       } while(p->next!=ptr);

       p->next=head;
   }
   else
   {
       Prev->next=ptr->next;
   }
   free(ptr);
}
int count(list *ptr)
{
  int ctr=0;

  do
  {
    ctr++;
    ptr=ptr->next;
  } while(ptr!=head);

  return ctr;
}
int sum(list *ptr)
{
  int ans=0;

  while(ptr!=head)
  {
    ans=ans+ptr->data;
    ptr=ptr->next;
  }
  return ans;
}

void copylist(list *ptr)
{
   copy *cptr,*p;
   int c=0;
   while(ptr!=head)
   {
      cptr=(copy*)malloc(sizeof(copy));
      cptr->data=ptr->data;
      cptr->next=NULL;
      ptr=ptr->next;
      cptr=
	    printf("\nSelf : %d\tData : %d\tNext : %d",cptr,cptr->data,cptr->next);
   }

}

list* reverse( list *ptr )
{
	list *next,*current ,*result = NULL;
	current = ptr;

	while(current != head )
	{
		next = current->next;
		current->next = result;
		result = current;
		current = next;
	}
	return (result);
}
void getTwoList()
{
  int ch=1;
  int item;
  list * newlst;

  while(ch==1)
  {
    clrscr();
    printf("\nWant to enter element in first List ...\nPress 1\n");
    scanf("%d",&ch);


    printf("\n\nEnter item:");
    scanf("%d",&item);

     newlst=(list *)malloc(sizeof(list *));
     newlst->data=item;
     newlst->next=NULL;

     if (l1==NULL)
	l1=newlst;
     else
	l1->next=newlst;

  }
  ch=1;

  while(ch==1)
  {
    clrscr();
    printf("\nWant to enter element in second List ...\nPress 1\n");
    scanf("%d",&ch);

    printf("\n\nEnter item:");
    scanf("%d",&item);

     newlst=(list *)malloc(sizeof(list *));
     newlst->data=item;
     newlst->next=NULL;

     if (l2==NULL)
	l2=newlst;
     else
	l2->next=newlst;

  }

}

list * merge()
{
  list *l3,*newlst;
  int item,c=0;

  while(l1!=NULL)
  {
     newlst=(list *)malloc(sizeof(list *));
     newlst->data=item;
     newlst->next=l1;
     if (c==0)
     {
       l3=newlst;
       c++;
     }
     else
     {
       l3->next=newlst;
     }
     l1=l1->next;
  }

  while(l2!=NULL)
  {
     newlst=(list *)malloc(sizeof(list *));
     newlst->data=item;
     newlst->next=l2;
     l3->next=newlst;
     l2=l2->next;
  }
  l3->next=NULL;
return l3;
}

