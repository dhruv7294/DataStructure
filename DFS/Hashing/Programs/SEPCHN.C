#include<stdio.h>
#include<alloc.h>
#include<conio.h>
struct SubLinkedList
{
  int data1;
  struct SubLinkedList *next;
};
typedef struct SubLinkedList Slist;

struct ParentLinkedList
{
  int data;
  struct ParentLinkedList *next;
  Slist *sptr;
};
typedef struct ParentLinkedList Plist;
Plist *Phead=NULL;
Slist *s1;

void main()
{
   Plist *p;
clrscr();

    Phead=(Plist *)malloc(sizeof(Plist));
    Phead->data=101;
    s1=(Slist *)malloc(sizeof(Slist));
    s1->data1=201;
    s1->next=(Slist *)malloc(sizeof(Slist));
    s1->next->data1=202;
    s1->next->next=(Slist *)malloc(sizeof(Slist));
    s1->next->next->data1=203;
    s1->next->next->next=NULL;

    Phead->sptr=s1;
    Phead->next=(Plist *)malloc(sizeof(Plist));

    Phead->next->sptr=NULL;
    Phead->next->data=102;

    s1=(Slist *)malloc(sizeof(Slist));
    s1->data1=301;
    s1->next=(Slist *)malloc(sizeof(Slist));
    s1->next->data1=302;
    s1->next->next=(Slist *)malloc(sizeof(Slist));
    s1->next->next->data1=303;
    s1->next->next->next=NULL;
    Phead->next->sptr=s1;


    Phead->next->next=(Plist *)malloc(sizeof(Plist));
    Phead->next->next->sptr=NULL;
    Phead->next->next->data=103;
    Phead->next->next->next=NULL;
     Phead->next->next->next->sptr=NULL;

    p=Phead;

 while(p!=NULL)
 {
   printf("\n%d",p->data);
   while(p->sptr!=NULL)
   {
	 printf("\t%d",p->sptr->data1);
	 p->sptr=p->sptr->next;
   }
   p=p->next;
 }

getch();



}
