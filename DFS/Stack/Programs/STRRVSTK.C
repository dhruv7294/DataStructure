#include<stdio.h>
#include<conio.h>

void push(char);
char pop();

int  top=-1;
char s[5];


void main()
{
   int i,j;
   char str[5],tmp[5];

clrscr();
   strcpy(str,"hello");

   for(i=0;i<strlen(str);i++)
   {
      push(str[i]);
   }
   for(j=0;j<strlen(str);j++)
   {
      tmp[j]=pop();
   }
   tmp[j]='\0';
   printf("\nstring : %s ",str);
   printf("\nreverse string : %s ",tmp);
getch();
}
void push(char ch)
{
  top++;
  s[top]=ch;
  printf("\n%c ",s[top]);
}
char pop()
{
   char ch=s[top];
   top--;
   printf("\n%c ",ch);
   return ch;
}

