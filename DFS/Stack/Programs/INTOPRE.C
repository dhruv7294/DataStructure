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
void display()
{
  int i;

	for(i=0; i<=top; i++)
	{
	  if (i==0)
		  printf("%4c", stack[i]);
	  else
		  printf("%c", stack[i]);
	}

	for(i=1; i<=20-top-1; i++)
	{
	  printf(" ");
	}
}

/* FUNCTION TO PUSH AN OPERATOR ON TO THE STACK */
void push(char x)
{

    stack[++top]=x;
    display();
    printf("%-20s", prefix);
}

/* FUNCTION TO POP A CHARACTER STORED ONTO THE STACK */
char pop()
{
	char ch=stack[top--];
	return(ch);

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
			printf("\n  %-5c", x);
			if (operand(x))
			{

			prefix[l++]=x;
			display();
			printf("%-10s", prefix);
			}
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
	{
		prefix[l++]=pop();
		display();
		printf("%-s", prefix);
	}




}


/* MAIN PROGRAM */
void main()
{
clrscr();
  init();
  printf("Enter an infix expression :\n");
  scanf("%s",infix);

  printf("\n----------------------------------------------------");
  printf("\n Symbol   Stack \t Reverse \n\t\t\t Polish(Prefix)");
  printf("\n----------------------------------------------------");

  infixtoprefix();
  strrev(prefix);
  printf("\n\nThe resulting prefix expression is %s",prefix);
getch();
} // End of main
