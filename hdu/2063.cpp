#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX=1010;
vector<int> G[MAX];
int match[MAX];
bool used[MAX];
int k,m,n;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i],w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=1;v<=m+n;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    while(cin>>k>>m>>n&&k)
    {
        for(int i=0;i<MAX;i++)
            G[i].clear();
        for(int i=0;i<k;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v+m);
        }
        cout<<bipartite_matching()<<endl;
    }
    return 0;
}

