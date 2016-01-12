/*	Write a program to insert node at specified position of the list  */

#include<conio.h>
#include<stdio.h>

struct SinglyList
{
  int data;
  struct SinglyList *next;
};

typedef struct SinglyList node;

node *head=NULL;
int isPrev=0;

// Functions Declarations
void create_head(int);
void insert_by_pos(node *,int);
node * search_by_pos(node *,int);

void display(node *);


void main()
{
  int item,ch,pos,cnt=0;
  node *loc;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert By position");
  printf("\n2 for display");
  printf("\n3 for exit");

  printf("\n\nEnter your choice:");
  scanf("%d",&ch);


  switch(ch)
  {
    case 1:  printf("\n\nEnter the position : ");
	     scanf("%d",&pos);

	     if(pos-1>cnt || pos-1<0)
	     {
	       printf("\n\nInvalid position ......!");
	       getch();
	     }
	     else
	     {

		     printf("\n\nEnter the item for the new node : ");
		     scanf("%d",&item);

		    if (head==NULL)
		    {
			 create_head(item);
		    }
		    else
		    {
			loc=search_by_pos(head,pos-1);
			insert_by_pos(loc,item);
		    }
		    cnt++;
		    printf("\n\n%d is inserted .....",item);
		    getch();
	     }
	     break;

    case 2: display(head);
	    getch();
	    break;


    case 3 :exit(0);
  }

 } while(ch!=3);

}

// Functions Implementations

// Used to create the head node
void create_head(int item)
{
     head=(node*) malloc(sizeof(node)); // malloc is used to allocate the memory
     head->data=item;
     head->next=NULL;
}

// Used to insert the new node at the given position
void insert_by_pos(node *currNode,int item)
{
     node *newNode;

     newNode=(node*) malloc(sizeof(node));
     newNode->data=item;

     if(currNode==head && isPrev==0)
     {
	newNode->next=currNode;
	head=newNode;
     }
     else
     {
	 newNode->next=currNode->next;
	 currNode->next=newNode;
     }
}

// Used to display the List of elements
void display(node *tempNode)
{
     if(head==NULL)
     {
	printf("\n\nList is empty.....");
	return;
     }

     while(tempNode!=NULL)
     {
	 printf("\n Self : %d\tData : %d\tNext : %d",tempNode,tempNode->data,tempNode->next);
	 tempNode=tempNode->next; // Used to move the pointer to the next node
     }

}

node * search_by_pos(node *tempNode,int pos)
{
  int i;
  node *prevNode;

  for(i=0;i<pos;i++)
  {
     prevNode=tempNode;
     tempNode=tempNode->next;
  }
  if(pos==0) // If new node will be inserted at first position
  {
     isPrev=0;
     return tempNode;
  }
  else
  {
     isPrev=1;
     return prevNode;
  }
}

