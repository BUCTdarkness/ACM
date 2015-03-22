#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=50005;
int n,x[maxn],y[maxn],l[maxn],r[maxn];
int main()
{
	while(cin>>n&&n!=-1)
	{
		int i,ans=0,s[maxn]={0};
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
			s[l[i]=r[i]=i]=s[i-1]+x[i];
		}
		y[0]=y[n+1]=-1;
		for(int i=1;i<=n;i++)
			while(y[l[i]-1]>=y[i])
			{
				l[i]=l[l[i]-1];
			}
		for(int i=n;i>0;i--)
			while(y[r[i]+1]>=y[i])
			{
				r[i]=r[r[i]+1];
			}
		for(int i=1;i<=n;i++)
		{
			ans=max(ans,(y[i])*(s[r[i]]-s[l[i]-1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
