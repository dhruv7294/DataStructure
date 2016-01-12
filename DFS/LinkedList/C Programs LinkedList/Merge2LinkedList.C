/*	Write a program to merge the two Linked Lists 	*/

#include<conio.h>
#include<stdio.h>

struct SinglyList
{
  int data;
  struct SinglyList *next;
};

typedef struct SinglyList node;

node *head1=NULL,*head2=NULL,*head3;


// Functions Declarations
void create_FirstList();
void create_SecondList();
void display_List(node *);
void merge_TwoLists();

void main()
{
  int item,ch;

clrscr();

 do
 {

  clrscr();
  printf("\n\n1 for insert First List");
  printf("\n2 for insert Second List");
  printf("\n3 for display First List");
  printf("\n4 for display Second List");
  printf("\n5 for Merge Two Lists");
  printf("\n6 for display merged List");
  printf("\n7 for exit");


  printf("\n\nEnter your choice:");
  scanf("%d",&ch);


  switch(ch)
  {
    case 1: create_FirstList();
	    break;

    case 2: create_SecondList();
	    break;

    case 3: display_List(head1);
	    getch();
	    break;

    case 4: display_List(head2);
	    getch();
	    break;

    case 5: merge_TwoLists();
	    break;

    case 6: display_List(head3);
	    getch();
	    break;

    case 7: exit(0);
  }

 } while(ch!=7);

}

// Functions Implementations

// Used to create the First List

void create_FirstList()
{
     int ch=1,item;
     node *list1;

	printf("\n\nEnter the item for the new node : ");
	scanf("%d",&item);

	head1=(node *)malloc(sizeof(node));
	head1->data=item;
	head1->next=NULL;
	list1=head1;

	printf("\n\nDo you want to cont....");
	printf("\nPress 1 to continue");
	printf("\nPress 0 to exit");

	printf("\n\nEnter your choice : ");
	scanf("%d",&ch);

	while(ch!=0)
	{

	      node *newNode;

	      printf("\n\nEnter the item for the new node : ");
	      scanf("%d",&item);

	      newNode=(node *)malloc(sizeof(node));
	      newNode->data=item;
	      newNode->next=NULL;
	      list1->next=newNode;
	      list1=list1->next;

	      printf("\n\nDo you want to cont....");
	      printf("\nPress 1 to continue");
	      printf("\nPress 0 to exit");

	      printf("\n\nEnter your choice : ");
	      scanf("%d",&ch);
	}

}

// Used to create the second List
void create_SecondList()
{
     int ch=1,item;
     node *list2;

	printf("\n\nEnter the item for the new node : ");
	scanf("%d",&item);

	head2=(node *)malloc(sizeof(node));
	head2->data=item;
	head2->next=NULL;
	list2=head2;

	printf("\n\nDo you want to cont....");
	printf("\nPress 1 to continue");
	printf("\nPress 0 to exit");

	printf("\n\nEnter your choice : ");
	scanf("%d",&ch);

	while(ch!=0)
	{

	      node *newNode;

	      printf("\n\nEnter the item for the new node : ");
	      scanf("%d",&item);

	      newNode=(node *)malloc(sizeof(node));
	      newNode->data=item;
	      newNode->next=NULL;
	      list2->next=newNode;
	      list2=list2->next;

	      printf("\n\nDo you want to cont....");
	      printf("\nPress 1 to continue");
	      printf("\nPress 0 to exit");

	      printf("\n\nEnter your choice : ");
	      scanf("%d",&ch);
	}


}
void display_List(node *tempNode)
{
  if(tempNode==NULL)
  {
      printf("\n\nList is empty.....");
      return;
  }
  while(tempNode!=NULL)
  {
       printf("\nSelf : %d\tData : %d\tNext : %d",tempNode,tempNode->data,tempNode->next);
       tempNode=tempNode->next;
  }

}


// Used to merhe the two lists
void merge_TwoLists()
{
	     node *list3,*tempNode=head1;

	     head3=head1;
	     list3=head3;

	     while(tempNode!=NULL)
	     {
	       list3=tempNode;
	       tempNode=tempNode->next;
	     }

	     list3->next=head2;
}
