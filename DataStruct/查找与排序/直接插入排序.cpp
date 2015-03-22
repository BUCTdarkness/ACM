#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1010;
void Insertsort(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			int temp=a[i];
			for(j=i-1;j>=0&&a[j]>temp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;
		}
	}
}
int main()
{
	int n;
	int a[maxn];
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Insertsort(a,n);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}
