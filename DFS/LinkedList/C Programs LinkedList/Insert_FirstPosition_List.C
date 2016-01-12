/*	Write a program to insert node at first position of the list  */

#include<conio.h>
#include<stdio.h>

struct SinglyList
{
  int data;
  struct SinglyList *next;
};

typedef struct SinglyList node;

node *head=NULL;

// Functions Declarations
void create_head(int);
node * insert_first(node *,int);
void display(node *);


void main()
{
  int item,ch;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert first");
  printf("\n2 for display");
  printf("\n3 for exit");

  printf("\n\nEnter your choice:");
  scanf("%d",&ch);


  switch(ch)
  {
    case 1:  printf("\n\nEnter the item for the new node : ");
	     scanf("%d",&item);

	     if(head==NULL)
	     {
		 create_head(item);
	     }
	     else
	     {
		head= insert_first(head,item);
	     }

	     printf("\n\n%d is inserted .....",item);
	     getch();
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

// Used to insert the new node at the first position
node * insert_first(node *headNode,int item)
{
     node *newNode;

     newNode=(node*) malloc(sizeof(node));
     newNode->data=item;
     newNode->next=headNode;

     return newNode;
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

