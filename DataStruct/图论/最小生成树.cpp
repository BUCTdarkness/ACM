#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define maxn 1000000
using namespace std;
struct Edge
{
	int u,v,w;
}edge[maxn];
int p[maxn];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
	int n;
	int m;
	int ans;
	while(cin>>n)
	{
		m=0;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				int x;
				cin>>x;
				if(x)
				{
					edge[m].u=i;
					edge[m].v=j;
					edge[m].w=x;
					m++;
				}
			}
		sort(edge,edge+m,cmp);
		for(int i=1;i<=maxn;i++)
			p[i]=i;
		for(int i=0;i<m;i++)
		{
			int x=find(edge[i].u);
			int y=find(edge[i].v);
			if(x!=y)
			{
				ans+=edge[i].w;
				p[x]=y;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
