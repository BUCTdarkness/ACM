#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX=1010;
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
int main()
{
    int T;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            for(int i=0;i<MAX;i++)
                G[i].clear();
            int n,m;
            cin>>n>>m;
            for(int i=0;i<m;i++)
            {
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                add(x,y,z);
            }
            cout<<"Case "<<kase<<": "<<max_flow(1,n)<<endl;
        }
    }
    return 0;
}
