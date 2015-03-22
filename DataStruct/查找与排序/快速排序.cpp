#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100010;
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
void ksort(int l,int h,int a[])
{
	if(h<l+2)
		return;
	int e=h,p=l;
	while(l<h)
	{
		while(++l<e&&a[l]<=a[p]);
		while(--h>p&&a[h]>=a[p]);
		if(l<h)
		{
			swap(a[l],a[h]);
		}
	}
	swap(a[h],a[p]);
	ksort(p,h,a);
	ksort(l,e,a);
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
		ksort(0,n,a);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}
