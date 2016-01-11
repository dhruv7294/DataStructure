#include<iostream.h>
#include<conio.h>

void main()
{

    int data[10]={0},pos=0,srNo,i,j,n,lb,ub,mid;
    clrscr();
    cout<<"\n\tHow many nos u want to enter :-->";
    cin>>n;
       //get data of array
    for(i=0;i<n;i++)
    {
	cout<<"\n\tEnter data["<<i+1<<"]:-->" ;
	cin>>data[i];

    }
    for(i=0;i<n;i++)
    {
	cout<<data[i]<<",";
    }
    cout<<"\n\tEnter No for Search:-->";
    cin>>srNo;

    lb=0;
    ub=n-1;

    while(lb<=ub)
    {
	    mid=(lb+ub)/2;

	    if(data[mid]<srNo)
	    {
		lb=mid+1;
	    }
	    else if(data[mid]>srNo)
	    {
		ub=mid-1;

	    }
	    else
	    {
		 cout<<"\n\tItem Found at position "<<mid+1;
		 break;
	    }
    }

	if(lb>ub)
		cout<<"\n\tItem Not found...!";
    getch();
/*    pos=LinearSearch(data,n,srNo);


    if (pos==-1)
    {
	    cout<<"\n\tUnSuccesful Search";
    }
    else
    {
	     cout<<"\n\tSuccesful Search at "<<pos+1<<" Position";
    }



}
int LinearSearch(int data[],int n,int srNo)
{

    int i,ctr=0;
    data[n]=srNo;
    for(i=0;i<n;i++)
    {
	 if(data[i]==srNo)
	 {
	     return i;
	 }
	 else
	 {
		ctr++;
	 }
    }
return -1;
 */
}