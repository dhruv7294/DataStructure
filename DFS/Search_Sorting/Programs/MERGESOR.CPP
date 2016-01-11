
#include<iostream.h>
#include<conio.h>
#define SIZE 20
void main()
{
  int A[SIZE],B[SIZE],C[SIZE];
  int i,j,k,n1,n2,n3;
clrscr();
   cout<<"\n\tEnter n for Array A  :-->";
   cin>>n1;

   for(i=0;i<n1;i++)
   {
	cout<<"Enter No "<<i+1<<":-->";
	cin>>A[i];
  }
   cout<<"\n\tEnter n for Array B  :-->";
   cin>>n2;

   for(i=0;i<n2;i++)
   {
	cout<<"Enter No "<<i+1<<":-->";
	cin>>B[i];
 }
  i=0,j=0,k=0;
  while(i<n1 && j<n2)
  {
      if(A[i]<=B[j])
      {
	 C[k++]=A[i++];
      }
      else
      {
	 C[k++]=B[j++];
      }
}
  if (j<n2)
  {
	  while(j<n2)
	  {
		C[k++]=B[j++];
	  }
  }
  if (i<n1)
  {
	  while(i<n1)
	  {
		C[k++]=A[i++];
	  }
  }
  n3=n1+n2;
   cout<<"\n\tThird Array...\n\t";

   for(k=0;k<n3;k++)
   {
	cout<<" "<<C[k]<<" ";
   }

getch();
}

