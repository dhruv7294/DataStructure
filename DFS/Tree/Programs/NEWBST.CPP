#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define NULL 0
struct Tree
{
  int data;
  struct Tree *left;
  struct Tree *right;
};

typedef struct Tree node;
node *Loc, *Par,*root;
void insert(node*);
void preorder(node*);
void inorder(node*);
void postorder(node*);
void find(node *,int);
void  del(node *,int);
case_a(node *,node *,node *);
case_b(node *,node *,node *);
case_c(node *,node *,node *);
int count_LeafNodes(node *p);
void main()
{
clrscr();
   node *p;
   int ctr=0;
   int item,ch,ich;
do
{
  out:
  clrscr();
  printf("\n ----------------");
  printf("\n   Tree Menu");
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
		if(ctr==0)
		{
		     printf("\n\nEnter Item :: ");
		     scanf("%d",&item);

		     root=(node *)malloc(sizeof(node));
		     root->data=item;
		     root->left=NULL;
		     root->right=NULL;
		     ctr++;
		}
		else
		{
		      insert(root);
		      ctr++;
		}
		break;

    case 2:     printf("\n\nEnter Item :: ");
		scanf("%d",&item);

		del(root,item);
		break;

    case 3:	  Loc = Par = NULL;
		  printf("\nEnter Item to be found : ");
		  scanf("%d",&item);

		  find(root,item);
		  if(Loc==NULL)
			 printf("\nItem not found...!");
		  else
			if(Par==NULL)
			  printf("\nItem is found at the root !....");
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
			case 1: preorder(root);
				getch();
				break;
			case 2: inorder(root);
				int totLeaves;
				totLeaves=count_LeafNodes(root);
				printf("\n\nTotal Leaf Nodes : %d",totLeaves);
				getch();
				break;
			case 3: postorder(root);
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

void inorder(node* p)
{
	if(p==NULL)
	{
	 printf("\nTree is Empty ....!");
	 return;
	}

	if(p->left != NULL)
	  inorder(p->left);

	printf("%d--->",p->data);

	if(p->right != NULL)
	  inorder(p->right);
}

void preorder(node* p)
{
	if(p==NULL)
	{
	 printf("\nTree is Empty...!");
	 return;
	}
	printf("%d--->",p->data);

	if(p->left != NULL)
	  preorder(p->left);

	if(p->right != NULL)
	  preorder(p->right);
}

void postorder(node* p)
{
	if(p==NULL)
	{
	 printf("\nTree is Empty...!");
	 return;
	}
	if(p->left != NULL)
	  postorder(p->left);

	if(p->right != NULL)
	  postorder(p->right);

	printf("%d--->",p->data);
}

void insert(node *p)
{
node *q;
	    q=(node*)malloc(sizeof(node));
	    printf("\nEnter data: ");
	    scanf("%d",&q->data);

	    q->left=NULL;
	    q->right=NULL;

	while(1)
	{
	 if(q->data < p->data)
	  {
		if(p->left!=NULL)
		 p=p->left;
		else
		 {
			p->left=q;
			break;
		 }
	  }
	  else
	  {
	  if(p->right!=NULL)
		  p=p->right;
		else
		{
		 p->right=q;
		 break;
		}
	  }
	}  // while
}

void find(node *t, int item)
{
 node *ptr, *prev;
	if(t==NULL)
	 {
	    Loc = Par = NULL;
	    return;
	 }
	if(item == t->data)
	 {
	    Loc = t;
	    Par = NULL;
	    return;
	 }
	 prev = t;
	 if( item < t->data)
		   ptr= t->left;
	  else
		  ptr= t->right;

	  while(ptr!=NULL)
	   {
	       if( ptr->data == item)
		  {
		   Loc= ptr;
		   Par = prev;
		   return;
		  }
		else
		 if (item < ptr->data)
		    {
		       prev = ptr;
		       ptr = ptr->left;
		    }
		 else
		   {
		       prev = ptr;
		       ptr = ptr->right;
		   }
	   }

	   Loc = NULL;
	   Par = prev;
	   return;
}

case_a(node *root,node *par,node *loc)
{
	if(par==NULL) /*item to be deleted is root node*/
		root=NULL;
	else
		if(loc==par->left)
			par->left=NULL;
		else
			par->right=NULL;
}

case_b( node *root,node *par, node *loc)
{
 node *child;

	/*Initialize child*/
	if(loc->left!=NULL) /*item to be deleted has lchild */
		child=loc->left;
	else /*item to be deleted has rchild */
		child=loc->right;

	if(par==NULL ) /*Item to be deleted is root node*/
		root=child;
	else
		if( loc==par->left) /*item is lchild of its parent*/
			par->left=child;
		else /*item is rchild of its parent*/
			par->right=child;
}

case_c( node *root,node *Par,node *Loc)
{
 node *ptr,*ptrsave,*suc,*parsuc;

/*Find inorder successor and its parent*/
ptrsave=Loc;
ptr=Loc->right;
	while(ptr->left!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->left;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->left==NULL && suc->right==NULL)
		case_a(root,parsuc,suc);
	else
		case_b(root,parsuc,suc);

	if(Par==NULL) /*if item to be deleted is root node */
		root=suc;
	else
		if(Loc==Par->left)
			Par->left=suc;
		else
			Par->right=suc;

	suc->left=Loc->left;
	suc->right=Loc->right;
}

void del(node *root,int item)
{

	if(root==NULL)
	{
		printf("Tree empty");
		return;
	}

	find(root,item);
	if(Loc==NULL)
	{
		printf("Item not present in tree");
		return;
	}

	if(Loc->left==NULL && Loc->right==NULL)
		case_a(root,Par,Loc);
	if(Loc->left!=NULL && Loc->right==NULL)
		case_b(root,Par,Loc);
	if(Loc->left==NULL && Loc->right!=NULL)
		case_b(root,Par,Loc);
	if(Loc->left!=NULL && Loc->right!=NULL)
		case_c(root,Par,Loc);
}

int count_LeafNodes(node *p)
{
   int cnt=0;
   while(p!=NULL)
   {
     if(p->left==NULL)
     {
	cnt++;
     }
     p=p->left;
   }
   p=root;
   while(p!=NULL)
   {
     if(p->right==NULL)
     {
	cnt++;
     }
     p=p->right;
   }
   return cnt;
}