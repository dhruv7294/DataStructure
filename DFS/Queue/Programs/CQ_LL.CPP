#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct CircularQueue
{
  int data;
  struct CircularQueue *next;
};
typedef struct CircularQueue CQue;
CQue *F=NULL,*R=NULL;

void insert(int);
void del();
void disp();

void main()
{
 int ch,item;
clrscr();
		do
		{
		  clrscr();
		  printf("\n 1 for Insert");
		  printf("\n 2 for Delete");
		  printf("\n 3 for Display");
		  printf("\n 4 for Exit");
		  printf("\n\t Enter choice:");
		  scanf("%d", &ch);

		    switch(ch)
		    {
		      case 1 : printf("\n\t Enter item for insertion:");
			       scanf("%d", &item);
			       insert(item);
			       getch();
			       break;

		      case 2 : del();
			       getch();
			       break;

		      case 3 : disp();
			       getch();
			       break;

		      case 4 : printf("\n\t Thanks...!");
			       getch();
			       exit(0);
			       break;

		      default : printf("\n\t Wrong choice...!");
				getch();
				break;
		    }
		}while(ch!=4);





getch();
}
void insert(int item)
{
 CQue *q;
 q=(CQue *)malloc(sizeof(CQue));
 q->data=item;

 if(R==NULL)
 {
    R=q;
    F=q;
    q->next=R;
 }
 else
 {
    q->next=F;
    R->next=q;
    R=q;
 }
  printf("\n\t%d is inserted!....",q->data);

}

void del()
{
   CQue *q;
   if(F==NULL && R==NULL)
   {
    printf("\n\tCircular Queue Underflow !....");
    getch();
    return;
   }
   if(F==R)
   {
     q=F;
     F=NULL;
     R=NULL;
   }
   else
   {
      q=F;
      F=F->next;
      R->next=F;
   }
     printf("\n\t%d is deleted!....",q->data);
     free(q);

}
void disp()
{
   CQue *ptr=F;
   if(R==NULL)
   {
    printf("\n\tCircular Queue Empty !....");
    return;

   }

   while(ptr!=R)
   {
     printf("\n\t%d",ptr->data);
     ptr=ptr->next;
   }
    printf("\n\t%d",R->data);


}