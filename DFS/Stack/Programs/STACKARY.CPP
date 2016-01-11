#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 5

void push(int s[],int &top,int item);
int peep(int s[],int top,int pos);
int pop(int s[],int &top);
void change(int s[],int top,int pos,int item);
void display(int s[],int top);

void main()
{
 int s[SIZE]={0};
 int top= -1;
 int ch, pos, item;
 clrscr();
		do
		{
		  clrscr();
		  printf("\n 1 for Push");
		  printf("\n 2 for Pop");
		  printf("\n 3 for Peep");
		  printf("\n 4 for Change");
		  printf("\n 5 for Display");
		  printf("\n 6. for Exit");

		  printf("\n\t Enter choice:");
		  scanf("%d", &ch);

		    switch(ch)
		    {
		      case 1 : printf("\n\t Enter item for push:");
			       scanf("%d", &item);
			       push(s,top,item);
			       getch();
			       break;

		      case 2 : item = pop(s,top);
			       if(item!=-1)
				  printf("\n\t%d is popped",item);
			       getch();
			       break;

		      case 3: printf("\n\tEnter pos for peep:");
			      scanf("%d",&pos);

			      item = peep(s,top,pos);

			      if(item!=-1)
				 printf("%d",item);

			      getch();
			      break;

		      case 4: printf("\n\tEnter new item :");
			      scanf("%d",&item);
			      printf("\n\tEnter pos:");
			      scanf("%d",&pos);
			      change(s,top,pos,item);
			      getch();
			      break;

		      case 5 : display(s,top);
			       getch();
			       break;

		      case 6 : printf("\n\t Thanks...!");
			       getch();
			       exit(0);
			       break;

		      default : printf("\n\t Wrong choice...!");
				getch();
				break;
		    }
		}while(ch!=6);
 getch();
}

void push(int s[],int &top,int item)
{
	     if(top==SIZE-1)
	      {
		printf("\n\t Stack overflow...!");
		return;
	      }
	      top++;

	      s[top] = item;

	      printf("\n\t %d is pushed", item);
}

int peep(int s[],int top,int pos)
{
 int item =-1;

	     if(pos < 1 || pos >top+1)
	      {
		printf("\n\tWrong position..!");
		return item;
	      }

	      item = s[top - pos +1];

	      return item;
}

int pop(int s[],int &top)
{
 int item=-1;

	     if(top==-1)
	      {
		printf("\n\tStack underflow...!");
		return item;
	      }

	      item = s[top];
	      top--;

	      return item;
}

void change(int s[],int top,int pos,int newItem)
{
 int item;
	     if(pos < 1 || pos >top+1)
	      {
		printf("\n\tWrong position..!");
		return;
	      }

	      item = s[top - pos +1];

	      s[top - pos +1] = newItem;

	      printf("\n\t%d is replaced with %d", item, newItem);
}
void display(int s[],int top)
{
	     printf("\n Top : %d", top+1);
	     if(top==-1)
	      {
		printf("\n\tStack is empty..!");
		return;
	      }

	      for(int i=top; i>=0; i--)
	      {
		printf("\n %d", s[i]);
	      }
}
