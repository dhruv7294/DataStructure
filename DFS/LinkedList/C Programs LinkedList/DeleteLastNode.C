/*  Write a program to delete last node from the list*/

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
void delet_last(node *);
void display(node *);
node * getLastNode(node *);

void main()
{
  int item,ch;
  node *last;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert");
  printf("\n2 for delete last");
  printf("\n3 for display");
  printf("\n4 for exit");

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

    case 2: if(head==NULL)
	    {
		printf("\n\ndeletion is not posiible....");
	    }
	    else
	    {
		last=getLastNode(head);
		delet_last(last);
	    }
	    getch();
	    break;

    case 3: display(head);
	    getch();
	    break;

    case 4 :exit(0);
  }

 } while(ch!=4);

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

// Used to diplay the list
void display(node *tempNode)
{
   if(tempNode==NULL)
   {
      printf("\n\nList is empty....");
      getch();
      return;
   }


   while(tempNode!=NULL)
   {
     printf("\nSelf : %d\tData : %d\tNext : %d",tempNode,tempNode->data,tempNode->next);
     tempNode=tempNode->next;
   }

}
// Used to delete the last node from the list
void delet_last(node * tempNode)
{
 if(tempNode==NULL) // If there is a single node in the list
 {
   printf("\n%d is deleted",head->data);
   head=NULL;
 }
 else
 {
    printf("\n%d is deleted",tempNode->next->data);
    tempNode->next=NULL;
 }

}

// Used to get the last node to delete
node *getLastNode(node *tempNode)
{
   node *prevNode=NULL;

   while(tempNode->next!=NULL)
   {
     prevNode=tempNode;
     tempNode=tempNode->next;
   }

   return prevNode;
}
