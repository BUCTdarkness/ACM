#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAX=20001;
int p[MAX],dis[MAX],n;
int find(int x)
{
	if(p[x]==x)
	{
		return x;
	}
	int tmp=p[x];
	p[x]=find(p[x]);
	dis[x]+=dis[tmp];
	return p[x];
}
int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
		{
		memset(dis,0,sizeof(dis));
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			p[i]=i;
		char cmd[5];
		while(scanf("%s",cmd)!=EOF&&cmd[0]!='O')
		{
			if(cmd[0]=='E')
			{
				int x;
				scanf("%d",&x);
				find(x);
				printf("%d\n",dis[x]);
			}
			else
			{
				int u,v;
				scanf("%d%d",&u,&v);
				dis[u]=abs(u-v)%1000;
				p[u]=v;
			}
		}
		}
	}
	return 0;	
}
