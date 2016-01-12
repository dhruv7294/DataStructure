/*  Write a program to display the sum of the elements of the list*/

#include<conio.h>
#include<stdio.h>

struct SinglyList
{
  int data;
  struct SinglyList *next;
};

typedef struct SinglyList node;

node *head=NULL,*lastNode;

// Functions Declarations
void create_head(int);
node * insert(node *,int);
int CalSum(node *);


void main()
{
  int item,ch,tot;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert");
  printf("\n2 for Get the sum of the elements");
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
		lastNode= insert(lastNode,item);
	     }

	     printf("\n\n%d is inserted .....",item);
	     getch();
	     break;

    case 2: tot=calSum(head);
	    if(tot==0)
	    {
		printf("\n\nList is empty.....");
	    }
	    else
	    {
		printf("\n\nSum of elements is : %d",tot);
	    }
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
     lastNode=head;
}

// Used to insert the new node at the last position
node * insert(node *lastNode,int item)
{
     node *newNode;

     newNode=(node*) malloc(sizeof(node));
     newNode->data=item;
     newNode->next=NULL;

     lastNode->next=newNode;

     return newNode;
}

// Used to calculate the sum of elements in the list
int calSum(node *tempNode)
{
     int sum=0;

     if(head==NULL)
     {
	return sum;
     }

     while(tempNode!=NULL)
     {
	 sum=sum + tempNode->data;
	 tempNode=tempNode->next; // Used to move the pointer to the next node
     }
     return sum;

}

