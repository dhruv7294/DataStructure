#include<stdio.h>
#include<conio.h>
void getArray(int x[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
	 scanf("%d",&x[i]);
    }
}
void printArray(int x[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
	printf("%d",x[i]);
	printf("\n");
    }
}
void selectSort(int x[],int n)
{
   int i,indx,j,large;
   indx=0;
      for(i=0;i<n;i++)
      {
	 large=x[i];
	   for(j=i+1;j<n;j++)
	   {
	      if(x[j]<large)
	      {
		 large=x[j];
		 indx=j;
	      }
	   }
	 x[indx]=x[i];
	 x[i]=large;
	 if(i==0 || i==1)
	 {
	 printArray(x,5);
	 }
      }
}
int bubbleSort(int x[], int n)
{
      int i,j,temp,cnt;
      for(i=0;i<n;i++)
	  {
	temp=x[0];
	cnt=0;
	  for(j=1;j<n;j++)
	  {
	     if(x[j]<temp)
	     {
		x[j-1]=x[j];
		x[j]=temp;
		cnt++;
	     }
	     temp=x[j];
	    }
    /*	     if(i==0)
	     {
	       printArray(x,5);
	     } */
	  if(cnt==0)
	  {
	    printf("%d",i);
	    return 0;
	  }
      }
}
void insertionSort(int x[], int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
     j=i+1;

     while(j!=0)
     {
	temp=x[j];
       if(temp<x[j-1])
       {
	 x[j]=x[j-1];
	 x[j-1]=temp;
       }
       j--;
     }
     if(i==2)
     {
       printArray(x,5);
     }
  }
}
void main()
{
    clrscr();
    int x[5];
    getArray(x,5);
    //selectSort(x,5);
    //bubbleSort(x,5);
    insertionSort(x,5);
    //printArray(x,5);
    getch();
}