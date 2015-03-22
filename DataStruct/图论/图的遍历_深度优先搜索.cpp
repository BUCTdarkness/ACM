#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#define maxn 1000
using namespace std;
int vis[maxn];
int G[maxn][maxn];
int n;
void read_graph()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
}
void dfs(int u)
{
	vis[u]=1;
	cout<<u<<" ";
	for(int v=0;v<n;v++)
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
	while(cin>>n)
	{
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		read_graph();
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				dfs(i);
			}
		}
	}
	return 0;
}
