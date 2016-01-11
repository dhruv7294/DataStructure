#include<stdio.h>
#include<conio.h>
void TOH(int n,char from,char to,char h);
void main()
{
   int n;
clrscr();
printf("\n\tEnter Number of Plates:-->");
scanf("%d",&n);
TOH(n,'A','C','B');
getch();
}
void TOH(int n,char from,char to,char h)
{
  if(n>0)
  {
    TOH(n-1,from,h,to);
    printf("\n\t%c --> %c",from,to);
    TOH(n-1,h,to,from);
    }

}
/*  	OUTPUT

       Enter Number of Plates:-->3
                                                                                
        A --> C                                                                 
        A --> B                                                                 
        C --> B                                                                 
        A --> C                                                                 
        B --> A                                                                 
        B --> C                                                                 
        A --> C                                                                 
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                
                                                                                

*/