#include<stdio.h>
#include<conio.h>
#define SIZE 10
void CQInsert(int CQ[],int n,int *F,int *R,int item)
{
	       if((*F==0 && *R==n) || (*F==*R+1))
	       {

		printf("\n\tQueue is Full!.. ");
		return;
	       }
	       if(*F==-1)
	       {
		  *F=0;
		  *R=0;
	       }
	       else if (*R==n)
	       {
		  *R=0;
	       }
	       else
	       {
		 (*R)++;
	       }
		 CQ[*R]=item;
	       return;
}

void CQDisplay(int CQ[],int F,int R,int n)
{
   int i;
     if(F==-1 && R==-1)
     {
	printf("Circular Queue is EMPTY...!");
	return;
     }
     printf("\n\tQueue Data:");
     if(F<=R)
     {
	 for(i=F;i<=R;i++)
	 {
		printf("%d ,",CQ[i]);
	 }

     }
     else
     {
	 for(i=F;i<n;i++)
	 {
		printf("%d ,",CQ[i]);
	 }
	 for(i=0;i<R;i++)
	 {
		printf("%d ,",CQ[i]);
	 }
     }
}
void main()
{

  int CQ[SIZE];
  int i,item,n,F=-1,R=-1;

  n=5;
clrscr();

   CQInsert(CQ,n,&F,&R,10);
   CQInsert(CQ,n,&F,&R,20);
   CQInsert(CQ,n,&F,&R,30);
   CQInsert(CQ,n,&F,&R,50);
   CQInsert(CQ,n,&F,&R,60);
   CQInsert(CQ,n,&F,&R,70);
   CQInsert(CQ,n,&F,&R,70);
   CQDisplay(CQ,F,R,n);
getch();
}

