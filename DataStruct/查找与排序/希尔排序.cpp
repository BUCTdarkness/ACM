#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1010;
void Shellsort(int *a,int n)
{
	int i,j,gap;
	for(gap=n/2;gap>0;gap=gap/2)
	{
		for(i=gap;i<n;i++)
		{
			int temp=a[i];
			for(j=i;j>=gap&&temp<a[j-gap];j=j-gap)
			{
				a[j]=a[j-gap];
			}
			a[j]=temp;
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
		Shellsort(a,n);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}
