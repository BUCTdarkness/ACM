#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1010;
int main()
{
	int n;
	int a[maxn];
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++)
		{
			int min=i;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[min])
				{
					min=j;
				}
			}
			int t=a[i];
			a[i]=a[min];
			a[min]=t;
		}
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
