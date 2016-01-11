#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0
typedef enum { thread,link } boolean;
struct Tree
{
  int data;
  struct Tree *left_ptr;
  struct Tree *right_ptr;
  boolean left;
  boolean right;
};

typedef struct Tree node;
node *Loc, *Par,*head=NULL,*root=NULL;

void insert(int);
void preorder();
void inorder();
void postorder();
void find(int);
void  del(int);
case_a(node *,node *,node *);
case_b(node *,node *,node *);
case_c(node *,node *,node *);
node * in_succ(node *);
node * in_pred(node *);
void createhead();
void main()
{
clrscr();
   node *p;
   int ctr=0;
   int item,ch,ich;

   createhead();
do
{
  out:
  clrscr();
  printf("\n ----------------");
  printf("\n   Threaded Tree Menu");
  printf("\n ----------------");

  printf("\n 1 for insert:");
  printf("\n 2 for delete:");
  printf("\n 3 for find:");
  printf("\n 4 for Traversal:");
  printf("\n 5 for exit");

  printf("\n\nEnter your choice: ");
  scanf("%d",&ch);
   switch(ch)
   {
      case 1:
		insert(item);
		break;

    case 2:     printf("\n\nEnter Item :: ");
		scanf("%d",&item);

		del(item);
		break;

    case 3:
		  printf("\nEnter Item to be found : ");
		  scanf("%d",&item);

		  find(item);
		  if(Loc==NULL)
			 printf("\nItem not found...!");
		  else
			  printf("\nItem is found in the tree !....");
		 getch();
		 break;
     case 4:
		do
		{
		  clrscr();
		  printf("\n ----------------");
		  printf("\n   Traversal Menu");
		  printf("\n ----------------");
		  printf("\n 1 for PreOrder:");
		  printf("\n 2 for InOrder:");
		  printf("\n 3 for PostOrder:");
		  printf("\n 4 Return To Main Menu:");
		  printf("\n\n Entrer your choice:- ");
		  scanf("%d",&ich);

		  switch(ich)
		  {
			case 1: preorder();
				getch();
				break;
			case 2: inorder();
				getch();
				break;
			case 3: //postorder(head);
				getch();
				break;
			case 4: goto out;
				break;
		  }
		}while(ich!=4);

		break;

     case 5: 	exit(0);
		break;
  }
}while(ch!=5);
getch();
}
void createhead()
{
	     head=(node *)malloc(sizeof(node));
	     head->data=-1;
	     head->left_ptr=head;
	     head->right_ptr=head;
	     head->left=thread;
	     head->right=link;

}
void inorder()
{
      node *p;
	if(head->left_ptr==head)
	{
	 printf("\nTree is Empty ....!");
	 return;
	}
	p=head->left_ptr;
	// Find the leftmost node and traverse it
	while(p->left==link)
	      p=p->left_ptr;

	printf("%d--->",p->data);

	while(1)
	{
	   p=in_succ(p);
	   if(p==head)
	      break;

	    printf("%d--->",p->data);
	}
}

void preorder()
{
       node *p;

	if(head->left_ptr==head)
	{
	 printf("\nTree is Empty...!");
	 return;
	}
	p=head->left_ptr;
	while(p!=head)
	{
	  printf("%d--->",p->data);
	  if(p->left==link)
	      p=p->left_ptr;
	  else if(p->right==link)
	     p=p->right_ptr;
	  else
	  {
	    while(p!=head && p->right==thread)
	       p=p->right_ptr;
	    if(p!=head)
	      p=p->right_ptr;
	  }
      }
}


void insert(int item)
{
     node *q,*parent,*location;


     printf("\nEnter data: ");
     scanf("%d",&item);

     find(item);
     parent=Par;
     location=Loc;

     if(location!=NULL)
     {
       printf("\nItem already exist !....");
       return;
     }
	    q=(node*)malloc(sizeof(node));
	    q->left=thread;
	    q->right=thread;
	    q->data=item;

	if(Par==head) //  tree is empty {p=head}
	{
	  head->left=link;
	  head->left_ptr=q;
	  q->left_ptr=head;
	  q->right_ptr=head;
	}
	else if(item<parent->data)
	{
	   q->left_ptr=parent->left_ptr;
	   q->right_ptr=parent;
	   parent->left=link;
	   parent->left_ptr=q;
	}
	else
	{
	  q->left_ptr=parent;
	  q->right_ptr=parent->right_ptr;
	  parent->right=link;
	  parent->right_ptr=q;
	}
}

void find(int item)
{
 node *ptr, *ptrsave;
	if(head->left_ptr==head) // Empty Tree
	 {
	    Loc = NULL;
	    Par=head;
	    return;
	 }
	if(item == head->left_ptr->data) // Item at left child of head
	 {
	    Loc = head->left_ptr;
	    Par = head;
	    return;
	 }

	 ptr=head->left_ptr;
	 while(ptr!=head)
	 {
	   ptrsave=ptr;
	   if( item < ptr->data)
	   {
	     if(ptr->left==link)
		   ptr= ptr->left_ptr;
	     else
		  break;
	   }
	   else if(item>ptr->data)
	   {
	     if(ptr->right==link)
		   ptr= ptr->right_ptr;
	     else
		  break;
	   }
	   if (item==ptr->data)
	   {
	      Loc=ptr;
	      Par=ptrsave;
	      return;
	   }
	}
	   Loc = NULL;
	   Par = ptrsave;
	   return;
}
case_a(node *head,node *par,node *loc)
{
	if(par==head) /*item to be deleted is head node*/
	{
		head->left=thread;
		head->left_ptr=head;
	 }
	else
	{
	       if(loc==par->left_ptr)
		{
			par->left=thread;
			par->left_ptr=loc->left_ptr;
		}
		else
		{
			par->right=thread;
			par->right_ptr=loc->right_ptr;
		}
       }
       free(loc);
}

case_b( node *head,node *par, node *loc)
{
 node *child,*s,*p;

	/*Initialize child*/
	if(loc->left==link) /*item to be deleted has lchild */
		child=loc->left_ptr;
	else /*item to be deleted has rchild */
		child=loc->right_ptr;

	if(par==head ) /*Item to be deleted is head node*/
		head->left_ptr=child;
	else
		if( loc==par->left_ptr) /*item is lchild of its parent*/
			par->left_ptr=child;
		else /*item is rchild of its parent*/
			par->right_ptr=child;

       s=in_succ(loc);
       p=in_pred(loc);

       if(loc->right==link)
	   s->left_ptr=p;
       else if(loc->left==link)
	   p->right_ptr=s;

       free(loc);
}

case_c( node *head,node *Par,node *Loc)
{
 node *ptr,*ptrsave,*suc,*parsuc;

	/*Find inorder successor and its parent*/
	ptrsave=Loc;
	ptr=Loc->right_ptr;

	while(ptr->left==link)
	{
		ptrsave=ptr;
		ptr=ptr->left_ptr;
	}
	suc=ptr;
	parsuc=ptrsave;

	Loc->data= suc->data;

	if(suc->left==thread && suc->right==thread)
		case_a(head,parsuc,suc);
	else
		case_b(head,parsuc,suc);
}

void del(int item)
{
	if(head==NULL)
	{
		printf("Tree empty");
		return;
	}
	find(item);
	if(Loc==NULL)
	{
		printf("Item not present in tree");
		return;
	}

	if(Loc->left==thread && Loc->right==thread) //  for zero child
		case_a(head,Par,Loc);
	if(Loc->left==link && Loc->right==thread) // for one left child
		case_b(head,Par,Loc);
	if(Loc->left==thread && Loc->right==link) // for one right child
		case_b(head,Par,Loc);
	if(Loc->left==link && Loc->right==link) // for two child left and right
		case_c(head,Par,Loc);
}
node * in_succ(node *ptr)
{
  node *suc;
  if(ptr->right==thread)
       suc=ptr->right_ptr;
  else
  {
    ptr=ptr->right_ptr;
    while(ptr->left==link)
    {
      ptr=ptr->left_ptr;
    }
    suc=ptr;
  }

   return suc;
}
node * in_pred(node *ptr)
{
  node *pred;
  if(ptr->left==thread)
       pred=ptr->left_ptr;
  else
  {
    ptr=ptr->left_ptr;
    while(ptr->right==link)
    {
      ptr=ptr->right_ptr;
    }
    pred=ptr;
  }
   return pred;
}