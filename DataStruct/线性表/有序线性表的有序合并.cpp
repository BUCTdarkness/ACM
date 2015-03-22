#include<iostream>
using namespace std;
#define MAX_LEN 300
void print(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i];
		if(i!=len-1)
			cout<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[MAX_LEN],b[MAX_LEN],c[MAX_LEN];
	int m,n;
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
		int i=0,j=0,k=0;
		while(k<m+n)
		{
			if(i<m&&j<n)
			{
				if(a[i]<b[j])
					c[k++]=a[i++];
				else
					c[k++]=b[j++];
			}
			if(i>=m)
			{
				c[k++]=b[j++];
			}
			if(j>=n)
			{
				c[k++]=a[i++];
			}
		}
		print(c,m+n);
	}
	return 0;
}
