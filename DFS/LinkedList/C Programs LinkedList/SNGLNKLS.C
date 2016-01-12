#include<stdio.h>
#include<conio.h>
struct LinkedList
{
  int data;
  struct LinkedList *next;
};

typedef struct LinkedList list;

list *head,*Prev,*head1,*head2,*head3,*head4,*uhead,*ihead=NULL;
list *l1=NULL,*l2=NULL,*l3=NULL,*cpLst=NULL;

void create_head(int);
void disp(list *);
list * insert(list *,int);
list * find(list *,int);
void del(list *);
int count(list *);
int sum(list *);
void copylist();
list* reverse(list*);
void merge();
void getTwoList();
void unionList();
void IntersectList();

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
	printf("\n12.Get two linked list");
	printf("\n13.Exit");

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

	  case 7:
		  copylist();
//		  disp(head4);
		  getch();
		  break;

	  case 8:t=reverse(head);
		 disp(t);
		 getch();
		 break;

	  case 9:
		 merge();
		 clrscr();
		 disp(head3);
		 getch();
		 break;

	  case 10:
		   unionList();
		   break;

	  case 11:
		   IntersectList();
		   break;

	  case 12:
		 getTwoList();
		 break;

	  case 13:exit(0);
	}
    } while(ch!=13) ;

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
  while(ptr!=NULL)
  {
    printf("\nSelf : %d\tData : %d\tNext : %d",ptr,ptr->data,ptr->next);
    ptr=ptr->next;
  }

}
list *insert(list *p,int item)
{
  list *q;
  q= (list *)malloc(sizeof(list));
  q->data=item;
  q->next=NULL;
  p->next=q;
  return q;
}

list * find(list *ptr,int item)
{
	while(ptr!=NULL)
	{
		if (item==ptr->data)
		{
			return ptr;

		}
		Prev=ptr;
		ptr=ptr->next;
	}
	 return NULL;
}
void del(list *ptr)
{
   if (ptr==head)
   {
       head=ptr->next;
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

  while(ptr!=NULL)
  {
    ctr++;
    ptr=ptr->next;
  }
  return ctr;
}
int sum(list *ptr)
{
  int ans=0;

  while(ptr!=NULL)
  {
    ans=ans+ptr->data;
    ptr=ptr->next;
  }
  return ans;
}
list* reverse( list *ptr )
{
	list *next,*current ,*result = NULL;
	current = ptr;

	while(current != NULL )
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
     clrscr();
     printf("\n\nEnter elements For the First List.....\n\n ");
     printf("\n\nEnter item:");
     scanf("%d",&item);

     head1=(list *)malloc(sizeof(list *));
     head1->data=item;
     head1->next=NULL;


  while(1)
  {
      printf("\nWant to continue ...\nPress 1\n");
      scanf("%d",&ch);

      if(ch==1)
      {
	printf("\n\nEnter item:");
	scanf("%d",&item);

	newlst=(list *)malloc(sizeof(list *));
	newlst->data=item;
	newlst->next=NULL;
	if (l1==NULL)
	{
		l1=head1;
		l1->next=newlst;
	}
	else
	{
		l1->next=newlst;
	}

	l1=l1->next;
     }
     else
     {
       break;
     }

  }
  ch=1;
     clrscr();
     printf("\n\nEnter elements For the Second List.....\n\n ");
     printf("\n\nEnter item:");
     scanf("%d",&item);

     head2=(list *)malloc(sizeof(list *));
     head2->data=item;
     head2->next=NULL;

  while(1)
  {

     printf("\nWant to continue ...\nPress 1\n");
     scanf("%d",&ch);
     if(ch==1)
     {
      printf("\n\nEnter item:");
      scanf("%d",&item);

     newlst=(list *)malloc(sizeof(list *));
     newlst->data=item;
     newlst->next=NULL;

     if (l2==NULL)
     {
	l2=head2;
	l2->next=newlst;
     }
     else
     {
	l2->next=newlst;
     }
     l2=l2->next;
     }
     else
     {
       break;
     }


  }

   disp(head1);
   disp(head2);
   getch();

}

void merge()
{
  head3=head1;
  l3=head1;

  while(l3->next!=NULL)
  {
     l3=l3->next;
  }
  l3->next=head2;
  while(l3!=NULL)
  {
     l3=l3->next;
  }
  l3->next=NULL;
  getch();

}

void copylist()
{
   list *p,*ptr=head;
   int c=0;

   while(ptr!=NULL)
   {
     p=(list *)malloc(sizeof(list *));
     p->data=ptr->data;
     p->next=NULL;
     if(c==0)
     {
	head4=p;
	cpLst=p;

	c++;
     }
     else
     {
      cpLst->next=p;
      cpLst=cpLst->next;
     }
     ptr=ptr->next;
   }

  disp(head4);
  getch();
}

void unionList()
{
  list *u3,*p,*ptr;
  int flag=0;

	l1=head1;
	uhead=(list *)malloc(sizeof(list *));
	uhead->data=head1->data;
	uhead->next=NULL;
	u3=uhead;
	l1=l1->next;

     while(l1!=NULL)
     {
       ptr=uhead;
       flag=0;
       while(ptr!=NULL)
       {
	 if(l1->data==ptr->data)
	 {
	   flag=1;
	 }
	ptr=ptr->next;
       }
       if(flag==0)
       {
		p=(list *)malloc(sizeof(list *));
		p->data=l1->data;
		p->next=NULL;
		u3->next=p;
		u3=u3->next;
       }
       l1=l1->next;
     }
     l2=head2;
     while(l2!=NULL)
     {
       ptr=uhead;
       flag=0;
       while(ptr!=NULL)
       {
	 if(l2->data==ptr->data)
	 {
	   flag=1;
	 }
	ptr=ptr->next;
       }
       if(flag==0)
       {
		p=(list *)malloc(sizeof(list *));
		p->data=l2->data;
		p->next=NULL;
		u3->next=p;
		u3=u3->next;
       }
       l2=l2->next;
     }
  disp(uhead);
  getch();
}

void IntersectList()
{
   list *ilist,*p,*ptr;
   int flag=0;
   l1=head1;
   while(l1!=NULL)
   {
	l2=head2;
	while(l2!=NULL)
	{
	 if(l1->data==l2->data)
	 {
	  if(ihead==NULL)
	  {
	    ihead=(list *)malloc(sizeof(list *));
	    ihead->data=l1->data;
	    ihead->next=NULL;
	    ilist=ihead;
	  }// end of ihead if
	  else
	  {
	    flag=0;
	    ptr=ihead;
	    while(ptr!=NULL)
	    {
	      if(ptr->data==l1->data)
	      {
		flag=1;
		break;
	      }
	      ptr=ptr->next;
	    } // end of ptr loop
	    if (flag==0)
	    {
	      p=(list *)malloc(sizeof(list *));
	      p->data=l1->data;
	      p->next=NULL;
	      ilist->next=p;
	      ilist=ilist->next;
	    }  // end of flag if
	  }// end of else

	} // end of if compare for same
	 l2=l2->next;
      }  // end of l2
	 l1=l1->next;
   } // end of l1
  disp(ihead);
  getch();
}