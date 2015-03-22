#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1000; 
int vis[maxn];
int G[maxn][maxn];
int n,m;
void read_graph()
{
	memset(G,0,sizeof(G));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x][y]=1;
		G[y][x]=1;
	}
}
void dfs(int u)
{
	vis[u]=1;
	for(int v=1;v<=n;v++)
	{
		if(G[u][v])
		{
			if(!vis[v])
			{
				dfs(v);
			}
		}
	}
}
int main()
{
	while(cin>>n>>m&&n&&m)
	{
		read_graph();
		int s=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				dfs(i);
				s++;
			}
		}
		if(s==1)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
