#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 20001
#define INF 1<<30
using namespace std;
struct Edge
{
	int from,to,dist;
};
struct HeapNode
{
	int d,u;
	bool operator < (const HeapNode &rhs) const
	{
		return d>rhs.d;
	}
};
int main()
{
	int n,s,m;
	while(cin>>n>>m)
	{
		s=1;
		vector<Edge> edges;
		vector<int> G[maxn];
		bool done[maxn];
		int d[maxn];
		for(int i=0;i<m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			edges.push_back((Edge){x,y,z});
			int m=edges.size();
			G[x].push_back(m-1);
		}
		priority_queue<HeapNode> q;
		for(int i=1;i<=n;i++)
			d[i]=INF;
		d[s]=0;
		memset(done,false,sizeof(done));
		q.push((HeapNode){0,s});
		while(!q.empty())
		{
			HeapNode x=q.top();
			q.pop();
			int u=x.u;
			if(done[u])
				continue;
			done[u]=true;
			for(int i=0;i<G[u].size();i++)
			{
				Edge &e=edges[G[u][i]];
				if(d[e.to]>d[u]+e.dist)
				{
					d[e.to]=d[u]+e.dist;
					q.push((HeapNode){d[e.to],e.to});
				} 
			}
		}
		for(int i=2;i<=n;i++)
		{
			cout<<d[i]<<endl;
			
		}
	}
	return 0;
}
