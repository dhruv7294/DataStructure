/*	Write a program to perform the following operation
	on the Singly Linked List (Insert, Delete, Display)*/

#include<conio.h>
#include<stdio.h>

struct SinglyList
{
  int data;
  struct SinglyList *next;
};

typedef struct SinglyList node;

node *head=NULL,*lastNode,*prevNode;

// Functions Declarations
void create_head(int);
node * insert(node *,int);
void display(node *);
void delet(node *);
node * search(node *,int);


void main()
{
  int item,ch;
  node *loc;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert");
  printf("\n2 for display");
  printf("\n3 for search");
  printf("\n4 for delete");
  printf("\n5 for exit");

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

    case 2: display(head);
	    getch();
	    break;

    case 3:
	    if(head==NULL)
	    {
		printf("\n\nList is empty.....");
		printf("\nSearching is not possible.....");
	    }
	    else
	    {

		    printf("\n\nEnter the item to be searched : ");
		    scanf("%d",&item);

		    loc=search(head,item);

		    if(loc==NULL)  // if item not found
		    {
			printf("\n\nItem not found ......");
		    }
		    else
		    {
			printf("\n\nItem found ......");
		    }
	    }
	    getch();
	    break;

    case 4:
	    if(head==NULL)
	    {
		printf("\n\nList is empty.....");
		printf("\ndeletion is not possible.....");
	    }
	    else
	    {
		    printf("\n\nEnter the item to be deleted : ");
		    scanf("%d",&item);

		    loc=search(head,item);

		    if(loc==NULL)  // if item not found
		    {
			printf("\n\nItem not found ......");
		    }
		    else
		    {
			delet(loc);
			printf("%d is deleted ....",item);
		    }
	    }

	    getch();
	    break;

   case 5 :exit(0);
  }

 } while(ch!=5);

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

// Used tp delete an item from the List
void delet(node *currNode)
{
     // if the current node is first node
     if(currNode==head)
     {
	 head=currNode->next;

	 /*     OR

	 head=head->next;

	 */

     }
     else // if the current node is middle or the last node
     {
	prevNode->next=currNode->next;
     }

     // Used to release the memory
     free(currNode);
}

// Used to search the item from the List
node * search(node *tempNode,int searchItem)
{

     while(tempNode!=NULL)
     {
	 if(tempNode->data == searchItem)
	 {
		// returns the address of the current node
		// where the search item is found
		return tempNode;
	 }

	 prevNode=tempNode; // used to maintain the previous of the each node
	 tempNode=tempNode->next;
     }

     // returns NULL when the item is not found
     return NULL;
}


