#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define size 5
struct node
{
  int no;
  struct node *next;
};
struct node* createlist(struct node* head)
{
   struct node *ptr;
  int i,value;
  for(i=0;i<size;i++)
  {
    printf("\n enter value:");
    scanf("%d",&value);
   if(i==0)
   {
      head=(struct node*)malloc(sizeof(struct node));
      head->no=value;
      head->next=NULL;
      ptr=head;
   }
   else
   {
     ptr->next=(struct node*)malloc(sizeof(struct node));
     ptr=ptr->next;
     ptr->no=value;
     ptr->next=NULL;
    }
 }
 return head;
}
searchdata(struct node *head)
{
   struct node *ptr;
   int pos=1,value;
    printf("\n enter value to search:");
 scanf("%d",&value);

   ptr=head;
   while(ptr!=NULL)
    {
      if(ptr->no==value)
      {
	printf("\n data found at %d",pos);
	ptr=ptr->next;
	pos=pos+1;
      }
      else
      {
	ptr=ptr->next;
	pos=pos+1;
      }
    }
    return 0;
}
searchbypos(struct node *head)
{
   struct node *ptr;
   int i=1,pos;
    printf("\nenter value to search:");
    scanf("%d",&pos);

   ptr=head;
   while(ptr!=NULL)
   {
     if(i==pos)
      {
	printf("\nAt position %d data is: %d",pos,ptr->no);
	return 0;
      }
      else
      {
	ptr=ptr->next;
	i=i+1;
      }
   }
   return 0;
}
struct node* insertfirst(struct node *head)
{
    struct node *ptr,*ptr1;
    int value;
     printf("\nenter value to add:");
     scanf("%d",&value);
     ptr=(struct node*)malloc(sizeof(struct node));
     ptr->no=value;
     ptr->next=head;
     head=ptr;
     return head;
}
insertlast(struct node *head)
{
     struct node *ptr,*ptr1;
     int value;
     printf("\nenter value to add:");
     scanf("%d",&value);
     ptr=head;
     while(ptr->next!=NULL)
     {
       ptr=ptr->next;
     }
     ptr1=(struct node*)malloc(sizeof(struct node));
     ptr1->next=NULL;
     ptr1->no=value;
     ptr->next=ptr1;

}
struct node* insert(struct node *head)
{
  struct node *ptr,*ptr1,*prev;
  int i=1,value,pos;
  printf("\nente position:");
  scanf("%d",&pos);
  if(pos==1)
  {
   return insertfirst(head);
  }
  printf("\nenter value to add:");
  scanf("%d",&value);
  ptr=head;
 for(i=1;i<pos;i++)
  {
    prev=ptr;
    ptr=ptr->next;
  }
      ptr1=(struct node*)malloc(sizeof(struct node));
      ptr1->no=value;
      ptr1->next=prev->next;
      prev->next=ptr1;
      return head;

}
void splitlink(struct node* &head,struct node *&head1)
{
    int pos,i;
    struct node* ptr,*prev;
    ptr=head;
   printf("enter position from which u split:");
   scanf("%d",&pos);
   for(i=1;i<pos;i++)
   {
      prev=ptr;
      ptr=ptr->next;
   }
   head1=ptr;
   prev->next=NULL;
 }
void mergelink(struct node* &head,struct node* &head1)
{
  struct node *ptr;
  ptr=head;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=head1;
}
void reverse(struct node* &head)
{
  struct node *ptr,*prev,*ptr1;
  int i,count=1;
  ptr=head;
  ptr1=head;
  while(ptr->next!=NULL)
  {
   ptr=ptr->next;
   count=count+1;
  }
  ptr=head;
  for(i=0;i<count;i++)
  {
	   while(ptr->next!=NULL)
	   {
	    prev=ptr;
	    ptr=ptr->next;
	   }
	   if(i==0)
	   {
	     head=ptr;
	     head->next=prev;
	   }
	   else
	   {
	     ptr->next=prev;
	   }
	    prev->next=NULL;
	    ptr=ptr1;
  }
  return;
}
void printlist(struct node* head)
{
  struct node *ptr;
   ptr=head;
 printf("\n");
while(ptr!=NULL)
{
  printf("addres:%d\t",ptr);
  printf("value:%d \t",ptr->no);
  printf("exit address:%d\t",ptr->next);
  printf("\n");
  ptr=ptr->next;
}

}

void main()
{
 struct node *head,*head1;
 head1=NULL;
 int value,n,exit=0;
 clrscr();
 printf("1:createlist \t 2:printlist \t 3:searchdata \t 4:searchbypos \t 5:insertfirst \n 6:insert \t 7:insertlast \t 8:splitlink \t 9:mergelist \t 10:reverse \t 11:exit");
 printf("\n");
while(exit!=1)
{
 printf("\n enter value from menu:");
 scanf("%d",&n);
 switch(n)
 {
  case 1:
  {
   head=createlist(head);
   break;
  }
  case 2:
  {
   printlist(head);
   break;
  }
  case 3:
  {
  searchdata(head);
   break;
  }
  case 4:
  {
   searchbypos(head);
   break;
  }
  case 5:
  {
   head=insertfirst(head);
   break;
  }
  case 6:
  {
   head=insert(head);
   break;
  }
  case 7:
  {
   insertlast(head);
   break;
  }
  case 8:
  {
   splitlink(head,head1);
    printlist(head);
    printf("\n");
   printlist(head1);
   break;
  }
  case 9:
  {
    mergelink(head,head1);
    printf("\n");
    printlist(head);
    break;
  }
  case 10:
  {
   reverse(head);
   printf("\n");
   printlist(head);
   break;
  }
  case 11:
  {
   exit=1;
   break;
  }
 }
}
getch();
}
