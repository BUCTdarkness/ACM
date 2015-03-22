#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXV=10010;
const int MAXM=10010;
const int INF=1<<30;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int V;
vector<edge> G[MAXV];
int h[MAXV];
int dist[MAXV];
int prevv[MAXV],preve[MAXV];
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}
int min_cost_flow(int s,int t,int f)
{
    int res=0;
    fill(h,h+V,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist,dist+V,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top();
            que.pop();
            int v=p.second;
            if(dist[v]<p.first)
            {
                continue;
            }
            for(int i=0;i<G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(int v=0;v<V;v++) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
int N,M;
int a[MAXM],b[MAXM],c[MAXM];
void solve()
{
    int s=0,t=N-1;
    V=N;
    for(int i=0;i<M;i++)
    {
        add_edge(a[i]-1,b[i]-1,1,c[i]);
        add_edge(b[i]-1,a[i]-1,1,c[i]);
    }
    cout<<min_cost_flow(s,t,2)<<endl;
}
int main()
{
    while(cin>>N>>M)
    {
        for(int i=0;i<M;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        solve();
    }
    return 0;
}
