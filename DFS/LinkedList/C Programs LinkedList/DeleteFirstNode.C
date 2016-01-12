/*  Write a program to delete first node from the list*/

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
void delet_first(node *);
void display(node *);

void main()
{
  int item,ch,tot;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert");
  printf("\n2 for delete first (head)");
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

    case 2: delet_first(head);
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
// Used to delete the first(head) node from the list
void delet_first(node * headNode)
{
 if(head==NULL)
 {
   printf("\n\nDeletion is not possible.....");
   return;
 }

 if(headNode->next==NULL) // If there is a single node in the list
 {
   head=NULL;
 }
 else
 {
   head=headNode->next;
 }
 printf("\n\n%d is deleted .....",headNode->data);
 free(headNode);

}