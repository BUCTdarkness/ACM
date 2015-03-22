//hdu 1827 求入度为0的强连通分量
//Tarjan algorithm
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#define INF 100000000;
using namespace std;
const int MAX=2500;
vector<int> G[MAX];
stack<int> st;
int dnf[MAX],low[MAX],belong[MAX],instack[MAX],sum[MAX],dep,num;
int val[MAX],cost[MAX];
int in[MAX];
void tarjan(int x)
{
    dnf[x]=low[x]=dep++;
    instack[x]=1;
    st.push(x);
    for(int i=0;i<G[x].size();i++)
    {
        int y=G[x][i];
        if(!dnf[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(instack[y])
        {
            low[x]=min(low[x],dnf[y]);
        }
    }
    if(dnf[x]==low[x])
    {
        int y=-1;
        while(y!=x)
        {
            y=st.top();
            st.pop();
            belong[y]=num;
            instack[y]=0;
         //   sum[num]++;
        }
        num++;
    }
}
void init()
{
    memset(in,0,sizeof(in));
    //memset(out,0,sizeof(out));
    memset(dnf,0,sizeof(dnf));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
   // memset(sum,0,sizeof(sum));
    memset(instack,0,sizeof(instack));
    memset(val,0,sizeof(val));
    for(int i=0;i<MAX;i++) G[i].clear();
    while(!st.empty()) st.pop();
    num=0;
    dep=1;
}
int main()
{
    int m,n;
    while(cin>>n>>m)
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&val[i]);
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
        }
        for(int i=1;i<=n;i++)
        {
            if(!dnf[i])
                tarjan(i);
        }
        for(int i=0;i<n;i++)
        {
            cost[i]=INF;
        }
        for(int i=1;i<=n;i++)
        {
            if(cost[belong[i]]>val[i-1])
                cost[belong[i]]=val[i-1];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                if(belong[i]!=belong[G[i][j]])
                {
                    in[belong[G[i][j]]]++;
                }
            }
        }
        int ans=0,sum=0;
        for(int i=0;i<num;i++)
        {
            if(in[i]==0)
            {
                ans++;
                sum+=cost[i];
            }
        }
        cout<<ans<<" "<<sum<<endl;
    }
    return 0;
}
