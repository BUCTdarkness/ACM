#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int m;
	int a[20][20];
	memset(a,0,sizeof(a));
	for(int i=1;i<12;i++)
	{
		a[i][1]=1;
	}
	for(int i=1;i<12;i++)
	{
		for(int j=2;j<2*i+1;j++)
		{
			a[i][j]=a[i][j-1]+a[i][j-2];
		}
	}
	while(cin>>m)
	{
		while(m--)
		{
			int n;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<2*(n-i-1);j++)
				{
					cout<<" ";
				} 
				for(int j=0;j<2*i+1;j++)
				{
					cout<<a[i][j];
					if(j!=2*i)
					{
						cout<<" ";
					}
				}
				cout<<endl;
			}
		}
	}
	return 0;
}