#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=1<<30;
int dp[13][10000];
int hire,pay,fire;
int month;
int extra(int i,int j)
{
    if(i<j)
    {
        return (j-i)*hire;
    }
    else if(i>j)
    {
        return (i-j)*fire;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int need[20];
    while(cin>>month&&month)
    {

        cin>>hire>>pay>>fire;
        int ma=-1,mi=INF;
        for(int i=1;i<=month;i++)
        {
            cin>>need[i];
            mi=min(mi,need[i]);
            ma=max(ma,need[i]);
        }
        for(int i=0;i<=month;i++)
        {
            for(int j=mi;j<=ma;j++)
            {
                dp[i][j]=i==0?0:INF;
            }
        }
        for(int i=1;i<=month;i++)
        {
            for(int j=need[i];j<=ma;j++)
            {
                if(i==1)
                {
                    dp[i][j]=dp[i-1][j]+extra(0,j)+pay*j;
                }
                else
                {
                    for(int k=need[i-1];k<=ma;k++)
                    {
                        dp[i][j]=min(dp[i][j],dp[i-1][k]+extra(k,j)+j*pay);
                    }
                }
            }
        }
        int ans=INF;
        for(int i=need[month];i<=ma;i++)
        {
            ans=min(ans,dp[month][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}

