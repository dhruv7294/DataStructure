#include<stdio.h>
#include<conio.h>
#include<string.h>
#define M 14
#define N 10

int arr[M][N]={0};
void Radix_Sort(int [],int);
void disp(int [M][N]);
int  FindMaxLen(int no[]);

void main()
{
 int no[M]={42,23,74,11,65,57,94,36,99,87,70,81,61},i,cnt=0;
clrscr();
/*   for(i=0;i<SIZE;i++)
   {
    printf("Enter no[%d] : ",i+1);
    scanf("%d",&no[i]);
   }*/
   cnt=FindMaxLen(no);
   printf("\nmaxlen:%d",cnt);
   getch();

   for(i=0;i<cnt;i++)
   {
    Radix_Sort(no,i+1);
    disp(arr);
   }
//getch();
}
void Radix_Sort(int no[],int pass)
{
 int i=0,rem,temp,cnt=0,j,c=0,k=0,l=0;
 for(i=0;i<N;i++)
 {
   arr[M][i]=0;
 }
 for(j=0;j<M;j++)
 {
    temp=no[j];
    l=0;
 while(temp>0)
 {
   l++;
    rem=temp%10;
    temp=temp/10;
    if (pass==l)
    {

    c=arr[N][rem];
    switch(rem)
    {
      case 0:  arr[c][0]=no[j];
	       break;
      case 1:  arr[c][1]=no[j];
	       break;
      case 2:  arr[c][2]=no[j];
	       break;
      case 3:  arr[c][3]=no[j];
	       break;
      case 4:  arr[c][4]=no[j];
	       break;
      case 5:  arr[c][5]=no[j];
	       break;
      case 6:  arr[c][6]=no[j];
	       break;
      case 7:  arr[c][7]=no[j];
	       break;
      case 8:  arr[c][8]=no[j];
	       break;
      case 9:  arr[c][9]=no[j];
	       break;

   }
   arr[N][rem]++;

   }// end of if
   } //  end of while
}// end of for

  clrscr();
  cnt=-1;
  for(i=0;i<M;i++)
  {
     for(j=0;j<arr[N][i];j++)
     {
       cnt++;
       no[cnt]=arr[j][i];
     }
     printf("\n%d\t %d",i,arr[M][i]);
  }

  printf("\nnew Array ..... \n\n");
  for (i=0;i<M;i++)
   {
     printf("%5d",no[i]);
   }


}

void disp(int arr[M][N])
{
  int i,j,t[M];
  printf("\n\t");
  for(j=0;j<M;j++)
  {
	printf("%5d",j);
  }
  printf("\n");
  printf("\t======================================================\n");
   for (i=0;i<M;i++)
   {
    printf("i : %d\t",i);
    for (j=0;j<N;j++)
    {
	printf("%5d",arr[i][j]);
    }
    printf("\n");
   }
   getch();
}
int  FindMaxLen(int no[])
{
  int max=0,i=0,j=0,cnt=0,rem;
  for(i=0;i<M;i++)
  {
    max=no[i];
    for(j=0;j<N;j++)
    {
       if(max<no[j])
	  max=no[j];
    }

  }

  while(max>0)
  {
    rem=max%10;
    max=max/10;
    cnt++;
  }
return cnt;


}