#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX=1010;
vector<int> G[MAX];
int match[MAX],r[MAX],c[MAX];
bool used[MAX];
int k,V,n;
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
    for(int v=1;v<=V;v++)
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
    while(cin>>n>>k)
    {
        V=n*2;
        for(int i=0;i<k;i++)
        {
            int r,c;
            scanf("%d%d",&r,&c);
            add_edge(r,n+c);
        }
        cout<<bipartite_matching()<<endl;
    }
    return 0;
}

