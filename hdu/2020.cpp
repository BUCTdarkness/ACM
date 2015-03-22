#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool cmp(int a,int b)
{
	return abs(a)>abs(b);
}
int a[200];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(i!=0)
				cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
