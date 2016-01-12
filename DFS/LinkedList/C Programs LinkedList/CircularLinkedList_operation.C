/* 	Write a program to perform the following operations in
	circular Linked List  (Insert, Delete, Display, Search)	*/

#include<conio.h>
#include<stdio.h>

struct CircularList
{
  int data;
  struct CircularList *next;
};

typedef struct CircularList node;

node *head=NULL,*lastNode,*prevNode;

// Functions Declarations
void create_head(int);
node * insert(node *,int);
void display(node *);
void delet(node *);
node * search(node *,int);

node * getLastNode(node *);

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
     head->next=head;
     lastNode=head;
}

// Used to insert the new node at the last position
node * insert(node *lastNode,int item)
{
     node *newNode;

     newNode=(node*) malloc(sizeof(node));
     newNode->data=item;
     newNode->next=head;

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

     while(tempNode->next!=head)
     {
	 printf("\n Self : %d\tData : %d\tNext : %d",tempNode,tempNode->data,tempNode->next);
	 tempNode=tempNode->next; // Used to move the pointer to the next node
     }
     printf("\n Self : %d\tData : %d\tNext : %d",tempNode,tempNode->data,tempNode->next);
}

// Used tp delete an item from the List
void delet(node *currNode)
{

     node *last;
     // if the current node is first node
     if(currNode==head)
     {
	 if(currNode->next==head) // When there is a single node in the list
	 {
		head=NULL;
		return;
	 }

	 last=getLastNode(head);
	 head=currNode->next;
	 // Used to attach the last node to the new head node
	 last->next=head;
     }
     else if(currNode->next==head) // if the current node is last node
     {
	  prevNode->next=head;
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

     while(tempNode->next!=head)
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

     // Used to check the last node item of the linked list
     if(tempNode->data == searchItem)
     {
		return tempNode;
     }

     // returns NULL when the item is not found
     return NULL;
}

node * getLastNode(node *tempNode)
{

    while(tempNode->next!=head)
    {
       tempNode=tempNode->next;
    }
    return tempNode;
}

