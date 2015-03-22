//最大流普通算法
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
bool used[MAX];
void add(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        edge &e=G[v][i];
        if(!used[e.to]&&e.cap>0)
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
        memset(used,0,sizeof(used));
        int f=dfs(s,t,INF);
        if(f==0) return flow;
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




