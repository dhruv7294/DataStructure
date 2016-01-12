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
      head->no=10;
      head->next=NULL;
      ptr=head;
   }
   else
   {
     ptr->next=(struct node*)malloc(sizeof(struct node));
     ptr=ptr->next;
     ptr->no=value;
     ptr->next=head;
    }
 }
 return head;
}
void printlist(struct node* head)
{
  struct node *ptr;
   ptr=head;
 printf("\n");
do
{
  printf("addres:%d\t",ptr);
  printf("value:%d \t",ptr->no);
  printf("exit address:%d\t",ptr->next);
  printf("\n");
  ptr=ptr->next;
}while(ptr!=head);
}

void main()
{
 struct node *head,*head1;
 head1=NULL;
 int value,n,exit=0;
 clrscr();
 printf("1:createlist \t 2:printlist \t 3:exit");
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
   exit=1;
   break;
  }
 }
}
getch();
}
