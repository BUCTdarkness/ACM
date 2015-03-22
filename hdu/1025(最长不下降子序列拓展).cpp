//该题用到了最长不下降子序列的nlogn算法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=500010;
int p[MAXN];
int dp[MAXN];
int n;
int DP()
{
    int low,up,mid,len=1;
    dp[1]=p[1];
    for(int i=1;i<=n;i++)
    {
        low=1;
        up=len;
        while(low<=up)
        {
            mid=(low+up)/2;
            if(dp[mid]>=p[i])
            {
                up=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        dp[low]=p[i];
        if(low>len)
            len++;
    }

    return len;
}
int main()
{
    int k=1;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            p[x]=y;
        }
        int len=DP();
        cout<<"Case "<<k++<<":"<<endl;
        cout<<"My king, at most "<<len<<" road";
        if(len!=1)
            cout<<"s";
        cout<<" can be built."<<endl<<endl;
    }
    return 0;
}
