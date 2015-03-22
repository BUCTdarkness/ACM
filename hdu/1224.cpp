#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=105;
int v[MAX];
int dp[MAX];
int pre[MAX];
int g[MAX][MAX];
void print(int n)
{
    if(n==1)
    {
        cout<<n;
        return;
    }
    print(pre[n]);
    cout<<"->"<<n;
}
int main(void)
{
    int T;
    while(cin>>T)
    {
        for(int k=1;k<=T;k++)
        {
            if(k!=1)
                cout<<endl;
            int n;
            cin>>n;
            memset(v,0,sizeof(v));
            memset(dp,0,sizeof(dp));
            memset(g,0,sizeof(g));
            memset(pre,0,sizeof(pre));
            for(int i=1;i<=n;i++)
            {
                cin>>v[i];
            }
            int m;
            cin>>m;
            for(int i=0;i<m;i++)
            {
                int x,y;
                cin>>x>>y;
                g[x][y]=1;
            }
            v[n+1]=0;
            for(int i=2;i<=n+1;i++)
            {
                for(int j=1;j<i;j++)
                {
                    if(g[j][i]&&dp[j]+v[i]>dp[i])
                    {
                        dp[i]=dp[j]+v[i];
                        pre[i]=j;
                    }
                }
            }
            cout<<"CASE "<<k<<"#"<<endl;
            cout<<"points : "<<dp[n+1]<<endl;
            cout<<"circuit : ";
            print(pre[n+1]);
            cout<<"->1"<<endl;
        }
    }
    return 0;
}
