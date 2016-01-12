#include<stdio.h>
#include<conio.h>
#define size 5
void push(int s[],int value,int &top)
{
	if(top==size)
	{
		printf("overflow");
		return;
	}
	top++;
	s[top]=value;
}

void pop(int &top)
{
	if(top==-1)
	{
		printf("underflow");
		return;
	}
	top--;
}

void display(int s[],int &top)
{       int i;
	if(top==-1)
	{
		printf("empty");
		return;
	}
	for(i=top;i>=0;i--)
	{
	      printf("%d ",s[i]);
	}
}

void peep(int s[],int pos, int &top)
{
		if(pos>=0 && pos<=top)
		{
			printf("%d",s[top-pos+1]);

		}
		else
		{
			printf("invalid pos");
		}

}

void main()
{
 clrscr();
 int s[size];
 int a,n,i,pos,value,temp=0;
 int top=-1;
 printf("enter your choice: \n1.push \n2.pop \n3.peep \n4.display \n5.exit");
 while(temp!=1)
 {
 printf("\n enter n:");
 scanf("%d",&n);

	switch(n)
	{
		case 1:
		{
			printf("enter value to be pushed:");
			scanf("%d",&value);
			push(s,value,top);
			break;
		}
		case 2:
		{
			pop(top);
			break;
		}
		case 3:
		{
			printf("enter value to be peaped:");
			scanf("%d",&pos);
			peap(s,pos,top);
			break;
		}
		case 4:
		{
			display(s,top);
			break;
		}
		case 5:
		{
			temp=1;
			break;
		}
		default:
		{
			printf("invalid choice!!!");
		}


	}
 }
  getch();
}