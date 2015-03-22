#include<iostream>
using namespace std;
#define MAX_LEN 300
int m,n;
int find(int x,int *a)
{
	for(int i=0;i<m;i++)
	{
		if(a[i]==x)
			return 1;
	}
	return 0;
}
void add(int x,int *a)
{
	a[m++]=x;
}
int main()
{
	int a[MAX_LEN],b[MAX_LEN];
	while(cin>>m)
	{
		for(int i=0;i<m;i++)
		{
			cin>>a[i];
		}
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		for(int i=0;i<m;i++)
		{
			cout<<a[i];
			if(i!=m-1)
				cout<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<b[i];
			if(i!=n-1)
				cout<<" ";
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			if(!find(b[i],a))
			{
				add(b[i],a);
			}
			for(int j=0;j<m;j++)
			{
				cout<<a[j];
				if(j!=m-1)
					cout<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
