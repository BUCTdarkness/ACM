#include<iostream>
#include<string.h>
using namespace std;
int a[10][10];
int b[10];
int maxstep=0;
int step;
int sum[10],Max;
int change(int m)
{
	int t=a[m-1][m-1];
	int l;
	for(int j=0;j<m-1;j++)
	{
		a[m-1][m-1-j]=a[m-1][m-j-2];
		l=m-j-2;
	}
	for(int j=0;j<m-1;j++)
	{
		a[m-1-j][l]=a[m-j-2][l];
	}
	for(int j=0;j<m-1;j++)
	{
		a[l][l]=a[l][l+j+1];
	}
	for(int j=0;j<m-2;j++)
	{
		a[m-1][l]=a[m-1][l+j+1];
	}
	a[m-2][m-1]=t;
	return a[l][l]+a[m-1][l]+a[m-1][m-1]+a[l][m-1];
}
void ans(int n)
{
	for(int i=1;i<=n;i++)
	{
		sum[i]=change(n+1);
	}
	Max=0;
	for(int i=1;i<=n;i++)
	{
		if(Max<sum[i])
		{
			Max=sum[i];
			step=i;
		}
	}
	cout<<"Max="<<Max<<endl;
	maxstep+=step;
}
int main ()
{
	int n;
	while(cin>>n)
	{
		maxstep=0;
		Max=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		if(n==3)
		{
			ans(3);
		}
		if(n==5)
		{
			ans(3);
			ans(5);
		}
		if(n==7)
		{
			ans(3);
			ans(5);
			ans(7);
		}
		if(n==9)
		{
			ans(3);
			ans(5);
			ans(7);
			ans(9);
		}
		cout<<a[n/2+1][n/2+1]<<endl;
		cout<<Max+(a[n/2+1][n/2+1])<<" "<<maxstep<<endl;
	}
	return 0;
}
