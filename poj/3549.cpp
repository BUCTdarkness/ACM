#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX=200010;
const int INF=1<<30;
struct edge{int to,cap,rev;};
vector<edge> G[MAX];
int level[MAX];
int iter[MAX];
void add(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=0;i<G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&& level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(e.cap>0&&level[v]<level[e.to])
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
            flow+=f;
    }
}
const int MAXV=20010;
int N,M;
int A[MAXV],B[MAXV];
int a[MAX],b[MAX],w[MAX];
void solve()
{
    int s=N,t=s+1;
    for(int i=0;i<N;i++)
    {
        add(i,t,A[i]);
        add(s,i,B[i]);
    }
    for(int i=0;i<M;i++)
    {
        add(a[i]-1,b[i]-1,w[i]);
        add(b[i]-1,a[i]-1,w[i]);
    }
    cout<<max_flow(s,t)<<endl;
}
int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        scanf("%d%d",&A[i],&B[i]);
    }
    for(int i=0;i<M;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&w[i]);
    }
    solve();
    return 0;
}


