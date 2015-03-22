#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const int MAX=10005;
const int MAX_R=50005;
struct Edge
{
	int u,v,w;
}edge[MAX_R];
int N,M,R;
int p[2*MAX];
bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int kruskal()
{
	sort(edge,edge+R,cmp);
	for(int i=0;i<2*MAX;i++)
	{
		p[i]=i;
	}
	int ans=0;
	for(int i=0;i<R;i++)
	{
		int x=find(edge[i].u);
		int y=find(edge[i].v);
		if(x!=y)
		{
			ans+=edge[i].w;
			p[x]=y;
		}
	}
	return ans;
}
int main()
{
	int t;
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d%d",&N,&M,&R);
			for(int i=0;i<R;i++)
			{
				int x,y,d;
				scanf("%d%d%d",&x,&y,&d);
				edge[i]=(Edge){x,y+N,-d};
			}
			printf("%d\n",10000*(N+M)+kruskal());
		}
	}
	return 0;
}

