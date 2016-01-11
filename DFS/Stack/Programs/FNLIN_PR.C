/* PROGRAM TO CONVERT INFIX TO PREFIX EXPRESSION USING STACK */
#include<stdio.h>
#include<string.h>
/*MACRO FUNCTION TO CHECK WHETHER GIVEN CHARACTER IS OPERAND OR NOT */
#define operand(x)(x>='a'&&x<='z' || x>='A'&&x<='Z' || x>='0'&&x<='9')
char infix[30],prefix[30],stack[30];
int top,i=0;

/* FUNCTION TO INITIALIZE THE STACK */
void init()
{
	top=-1;
}

/* FUNCTION TO PUSH AN OPERATOR ON TO THE STACK */
void push(char x)
{
    stack[++top]=x;
}

/* FUNCTION TO POP A CHARACTER STORED ONTO THE STACK */
char pop()
{
	return(stack[top--]);
}

/* FUNCTION TO RETURN IN STACK PRIORITY OF A CHARACTER */
int isp(char x)
{
int y;
y=(x=='('?6:x=='^'?4:x=='*'?2:x=='/'?2:x=='+'?1:x=='-'?1:x==')'?0:-1);
return y;
}

/* FUNCTION TO RETURN INCOMING CHARACTER'S PRIORITY */
int icp(char x)
{
int y;
y=(x=='('?6:x=='^'?4:x=='*'?2:x=='/'?2:x=='+'?1:x=='-'?1:x==')'?4:-1);
return y;
}

/* FUNCTION TO CONVERT THE GIVEN INFIX TO PREFIX EXPRESSION */
void infixtoprefix()
{
	int j,l=0;
	char x,y;
	stack[++top]='\0';
	for (j=strlen(infix)-1; j>=0; j--)
		{
			x=infix[j];
			if (operand(x))
				prefix[l++]=x;
			else
				if (x=='(')
					while ((y=pop())!=')')
						prefix[l++]=y;
				else
					{
						while (isp(stack[top])>=icp(x))
							prefix[l++]=pop();
						push(x);
					}
		}
	while (top>=0)
		prefix[l++]=pop();
}

/* MAIN PROGRAM */
void main()
{
clrscr();
  init();
  printf("Enter an infix expression :\n");
  scanf("%s",infix);
  infixtoprefix();
  printf("\nnew ....The resulting prefix expression is %s",prefix);
  strrev(prefix);
  printf("The resulting prefix expression is %s",prefix);
getch();
} // End of main