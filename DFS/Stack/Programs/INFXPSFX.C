#include<stdio.h>
#include<conio.h>
#define SIZE 50
char stack[SIZE],infix[SIZE],postfix[SIZE];
int top=-1;
void push(char symbol)
{
   if(top>SIZE)
   {
     printf("\nStack Overflow!....");
     getch();
     return;
   }
   stack[top++]=symbol;
}
int pop()
{
  if(top==-1)
  {
     printf("\nStack Underflow!....");
     getch();
     return;
  }
  return (stack[top--]);
}

void infix_to_postfix()
{
  int len,i,p=0,prec;
  char ch=')';

  stack[top]='#';
  len=strlen(infix);
  infix[len]='#';

  for(i=0;i<=len;i++)
  {
    if(!isspace(infix[i]))
    {
      switch(infix[i])
      {
	case '(': push(infix[i]);
		  break;

	case ')': while(ch!='(')
		  {
		    ch=pop();
		    postfix[p++]=ch;
		  }
		  break;
	case '+':
	case '-':
	case '/':
	case '*':                      	case '%':
	case '^': prec=get_prec(infix[i]);
		  while(stack[top]!='#' && prec<=get_prec(stack[top]))
		  {
		       postfix[p++]=pop();
		  }

		  push(infix[i]);
		  break;
       default : postfix[p++]=infix[i];
      }
    }

  }
}
int get_prec(char symbol)
{
  switch(symbol)
  {
    case '(':  return 0;

    case '+':
    case '-':  return 1;
    case '*':
    case '/':
    case '%':  return 2;
    case '^':  return 3;
  }
}

void main()
{

clrscr();
  printf("\nEnter infix Expression : ");
  fflush(stdin);
  gets(infix);
  infix_to_postfix();
  printf("\n\nPostfix : %s\n",postfix);
getch();
}
