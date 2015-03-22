#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=101;
int a[MAX],f1[MAX],f2[MAX];
int main()
{
	int n,m;
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			f1[i]=1;
			cin>>a[i];
			for(int j=1;j<=i;j++)
			{
				if(a[j]<a[i]&&f1[j]+1>f1[i])
					f1[i]=f1[j]+1;
			}
		}
		for(int i=n;i>=1;i--)
		{
			f2[i]=1;
			for(int j=n;j>=i;j--)
			{
				if(a[j]<a[i]&&f2[j]+1>f2[i])
					f2[i]=f2[j]+1;
			}
		}
		m=-1;
		for(int i=1;i<=n;i++)
			m=max(f1[i]+f2[i]-1,m);
		cout<<n-m<<endl;
	}
	return 0;	
}
