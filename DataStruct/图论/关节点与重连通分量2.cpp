#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int v=1000;
int edge[v][v];
bool cut[v],bridge[v][v];
int low[v],dfn[v],vis[v];
void cutt(int cur,int father,int dep,int n)
{
    vis[cur]=1;
    dfn[cur]=low[cur]=dep;
    int children=0;
    for(int i=0;i<n;i++)
    {
        if(edge[cur][i])
        {
            if(i!=father&&vis[i]==1)
            {
                if(dfn[i]<low[cur])
                {
                    low[cur]=dfn[i];
                }
            }
            if(vis[i]==0)
            {
                cutt(i,cur,dep+1,n);
                children++;
                if(low[i]<low[cur])
                {
                    low[cur]=low[i];
                }
                if((father==-1&&children>1)||(father!=-1&&low[i]>=dfn[cur]))
                    cut[cur]=true;
                if(low[i]>dfn[cur])
                {
                    bridge[cur][i]=bridge[i][cur]=true;
                }
            }
        }
    }
    vis[cur]=2;
}
int main()
{
    int n;
    while(cin>>n)
    {
        memset(cut,false,sizeof(cut));
        memset(edge,0,sizeof(edge));
        memset(vis,0,sizeof(vis));
        memset(low,0,sizeof(low));
        memset(dfn,0,sizeof(dfn));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>edge[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            cutt(i,-1,0,n);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(cut[i])
            {
                sum++;
            }
        }
        cout<<sum<<endl;
        for(int i=0;i<n;i++)
        {
            if(cut[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
