#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX=100000;
int dp[MAX],c[MAX],w[MAX];
int v;
void ZeroOnePack(int cost,int weight)
{
    for(int i=v;i>=cost;i--)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}
void CompletePack(int cost, int weight)
{
    for(int i=cost;i<=v;i++)
    {
        dp[i]=max(dp[i],dp[i-cost]+weight);
    }
}
void MutiplePack(int cost,int weight,int cnt)
{
    if(v<=cnt*cost)
    {
        CompletePack(cost,weight);
        return;
    }
    else
    {
        int k=1;
        while(k<=cnt)
        {
            ZeroOnePack(k*cost,k*weight);
            cnt=cnt-k;
            k=2*k;
        }
        ZeroOnePack(cnt*cost,cnt*weight);
    }
}
int main()
{
    int n;
    while(cin>>n&&n>0)
    {
        v=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&c[i],&w[i]);
            v+=c[i]*w[i];
        }
        int sum=v;
        v/=2;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            MutiplePack(c[i],c[i],w[i]);
        }
        cout<<sum-dp[v]<<" "<<dp[v]<<endl;
    }
    return 0;
}
