#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stack>
#include<vector>
#define maxn 51
using namespace std;
int edge[maxn][maxn];
vector<int> g[maxn];
int n;
int topo[maxn];
int indegree[maxn];
void read_graph()
{
	for(int i=0;i<n;i++)
	{
		g[i].clear();
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>edge[i][j];
			if(edge[i][j])
			{
				g[i].push_back(j);
				indegree[j]++;
			}
		}
}
void toposort()
{
	stack <int> s;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			s.push(i);
		}
	}
	int count=0;
	int topo[maxn];
	memset(topo,0,sizeof(topo));
	while(!s.empty())
	{
		int u=s.top();
		s.pop();
		topo[count++]=u;
		for(int i=0;i<g[u].size();i++)
		{
			int v=g[u][i];
			if(--indegree[v]==0)
			{
				s.push(v);
			}
		}
	}
	if(count<n)
	{
		cout<<"ERROR"<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<topo[i]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	while(cin>>n)
	{
		memset(edge,0,sizeof(edge));
		memset(indegree,0,sizeof(indegree));
		read_graph();
		toposort();
	}
	return 0;
}
