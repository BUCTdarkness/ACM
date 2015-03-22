#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define maxn 1000
using namespace std;
vector<int> G[maxn];
int cc=0;
int low[maxn],pre[maxn];
bool iscut[maxn];
int dfs_clock=0;
void readgraph(int n)
{
	dfs_clock=0;
	cc=0;
	memset(low,0,sizeof(low));
	memset(iscut,false,sizeof(iscut));
	memset(pre,0,sizeof(pre));
	for(int i=0;i<n;i++)
	{
		G[i].clear();
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			if(x)
			{
				G[i].push_back(j);
			}
		}
}
int dfs(int u,int fa)
{
	int lowu=pre[u]=++dfs_clock;
	int child=0;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(!pre[v])
		{
			child++;
			int lowv=dfs(v,u);
			lowu=min(lowu,lowv);
			if(lowv>=pre[u])
			{
				iscut[u]=true;
			}
		}
		else if(pre[v]<pre[u]&&v!=fa)
		{
			lowu=min(lowu,pre[v]);
		}
	}
	if(fa<0&&child==1)
	{
		iscut[u]=false;
	}
	low[u]=lowu;
	return lowu;
}
int main()
{
	int n;
	while(cin>>n)
	{
		readgraph(n);
		for(int i=0;i<n;i++)
		{
			if(!pre[i])
			{
				dfs(i,-1);
			}
		}
		for(int i=0;i<n;i++)
		{
			if(iscut[i])
				cc++;
		}
		cout<<cc<<endl;
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(iscut[i])
			{
				flag=1;
				cout<<i<<" ";
			}
		}
		if(flag)
			cout<<endl;
		
	}
	return 0;
}
