#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1010;
void BInsertsort(int a[],int n)
{
	int i,j,high,low,m;
	for(i=1;i<n;i++)
	{
		int temp=a[i];
		low=0;
		high=i;
		while(low<high)
		{
			m=(low+high)/2;
			if(temp>=a[m])
			{
				low=m+1;
			}
			else
			{
				high=m;
			}
		}
		for(j=i-1;j>=low;j--)
		{
			a[j+1]=a[j];
		}
		a[low]=temp;
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
		BInsertsort(a,n);
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	} 
	return 0;
}
