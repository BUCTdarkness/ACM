//Tarjan algorithm
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
using namespace std;
const int MAX=100005;
vector<int> G[MAX];
stack<int> st;
int dnf[MAX],low[MAX],belong[MAX],instack[MAX],sum[MAX],dep,num;
int in[MAX],out[MAX];
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
            sum[num]++;
        }
        num++;
    }
}
void init()
{
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(dnf,0,sizeof(dnf));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(sum,0,sizeof(sum));
    memset(instack,0,sizeof(instack));
    for(int i=0;i<MAX;i++) G[i].clear();
    while(!st.empty()) st.pop();
    num=0;
    dep=1;
}
int main()
{
    int T;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            int n,m;
            cin>>n>>m;
            init();
            for(int i=0;i<m;i++)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                G[x].push_back(y);
            }
            for(int i=1;i<=n;i++)
                if(!dnf[i])
                    tarjan(i);
            if(num==1)
            {
                printf("Case %d: -1\n",kase);
                continue;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<G[i].size();j++)
                {
                    if(belong[i]!=belong[G[i][j]])
                    {
                        out[belong[i]]++;
                        in[belong[G[i][j]]]++;
                    }
                }
            }
            __int64 ans=0,tmp;
            for(int i=0;i<num;i++)
            {
                if(in[i]==0||out[i]==0)
                {
                    tmp=sum[i];
                    ans=max(ans,tmp*(tmp-1)+(n-tmp)*(n-tmp-1)+tmp*(n-tmp)-m);
                }
            }
            printf("Case %d: ",kase);
            cout<<ans<<endl;
        }
    }
    return 0;
}
