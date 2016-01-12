/*  Write a program to delete node from the given position
    of the list*/

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
node * search_by_pos(node *,int);
void delet_by_pos(node *);
void display(node *);


void main()
{
  int item,ch,pos,cnt=0;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert");
  printf("\n2 for delete by position");
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
	     cnt++;
	     printf("\n\n%d is inserted .....",item);
	     getch();
	     break;

    case 2:  printf("\n\nEnter the position  : ");
	     scanf("%d",&pos);

	     if(pos>cnt || pos<0)
	     {
	       printf("\n\nInvalid position....");
	     }
	     else
	     {

		     node *loc;

		     loc=search_by_pos(head,pos-1);
		     delet_by_pos(loc);

		     printf("\n\n%d is deleted",loc->data);
		     cnt--;
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

// Used to search the node from the specified position

node* search_by_pos(node *tempNode,int pos)
{
   int i;

   for(i=0;i<pos;i++)
   {
     prevNode=tempNode;
     tempNode=tempNode->next;
   }

   return tempNode;
}

// Used to delete the node

void delet_by_pos(node *currNode)
{
     if(currNode==head) // if the node is first (head) node
     {
	head=head->next;
     }
     else
     {
       prevNode->next=currNode->next;
     }
}