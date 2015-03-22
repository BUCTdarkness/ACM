#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=202;
const int INF=1<<30;
int N,K;
int a[MAX];
int cost[MAX][MAX];
int dp[MAX][MAX];
int main()
{
    int T=1;
    while(cin>>N>>K&&N&&K)
    {
        for(int i=1;i<=N;i++)
            cin>>a[i];
        for(int i=1;i<=N;i++)
        {
            for(int j=i;j<=N;j++)
            {
                cost[i][j]=0;
                for(int k=i;k<=j;k++)
                {
                    cost[i][j]+=abs(a[k]-a[(i+j)/2]);
                }
            }
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                dp[i][j]=INF;
            }
        for(int i=1;i<=N;i++)
        {
            dp[i][1]=cost[1][i];
        }

        for(int j=2;j<=K;j++)
        {
            for(int i=j;i<=N;i++)
            {
                for(int k=j;k<=i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k-1][j-1]+cost[k][i]);
                }
            }
        }
        cout<<"Chain "<<T<<endl;
        T++;
        cout<<"Total distance sum = "<<dp[N][K]<<endl<<endl;
    }
    return 0;
}
