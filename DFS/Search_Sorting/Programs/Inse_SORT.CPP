
#include<iostream.h>
#include<conio.h>
#include<process.h>
#define SIZE 10
void main()
{
     int data[SIZE]= {0},n=0,i,j,k,min=0, temp=0,pos=0;
clrscr();
   cout<<"\n\tEnter How Many nos U want to Enter :-->";
   cin>>n;


   for(i=0;i<n;i++)
   {
	cout<<"Enter No "<<i+1<<":-->";
	cin>>data[i];
  }


   for(i=0;i<n;i++)

   {
	min=data[i];
	for(j=i+1;j<n;j++)
	{
		if(data[j]<min)
		{
			min=data[j];
			pos=j;
		}
	}
	   cout<<"\n\t\tPass..."<<i;
	   for(k=0;k<n;k++)
	   {
		cout<<" "<<data[k]<<" ";
	   }

	temp=data[i];
	data[i]=data[pos];
	data[pos]=temp;
  }



   cout<<"\n\tAfter Sorting...";
   for(i=0;i<n;i++)
   {
	cout<<" "<<data[i ]<<" ";
   }


getch();
}



