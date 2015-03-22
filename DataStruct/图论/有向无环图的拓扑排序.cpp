#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1000
using namespace std;
int G[maxn][maxn];
int n;
int topo[maxn];
int c[maxn];
int t;
int indegree[maxn];
void read_graph()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>G[i][j];
		}
}
bool dfs(int u)
{
	c[u]=-1;
	for(int v=0;v<n;v++)
	{
		if(G[u][v])
		{
			if(c[v]<0)
				return false;
			else
				if(!c[v]&&!dfs(v))
					return false;
		}
	}
	c[u]=1;
	topo[--t]=u;
	return true;
}
bool toposort()
{
	t=n;
	memset(c,0,sizeof(c));
	for(int u=0;u<n;u++)
	{
		if(!c[u])
		{
			if(!dfs(u))
				return false;
		}
	}
	return true;
}
int main()
{
	while(cin>>n)
	{
		memset(G,0,sizeof(G));
		memset(indegree,0,sizeof(indegree));
		read_graph();
		if(toposort())
		{
			for(int i=0;i<n;i++)
			{
				cout<<topo[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			cout<<"ERROR"<<endl;
		}
	}
	return 0;
}
