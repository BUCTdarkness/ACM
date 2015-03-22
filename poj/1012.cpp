#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int ans[14]={0};
	int k;
	while(cin>>k&&k)
	{
		if(ans[k])
		{
			cout<<ans[k]<<endl;
			continue;
		}
		int n=2*k;
		int s[30]={0};
		int m=1;
		for(int i=1;i<=k;i++)
		{
			s[i]=(s[i-1]+m-1)%(n-i+1);
			if(s[i]<k)
			{
				i=0;
				m++;
			}
		}
		ans[k]=m;
		cout<<m<<endl;
	}
	return 0;
}
