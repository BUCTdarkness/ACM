//dp[i][j]=max(dp[i][j-1],max(dp[i-1][t])))+data[i];
//cur[j]=dp[i][j];
//pre[j]=dp[i-1][j];
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX=1000010;
const int INF=0x80000000;
int n,m;
int data[MAX];
int cur[MAX];
int pre[MAX];
void input()
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&data[i]);
    }
}
int max_sum()
{
    cur[0]=0;
    memset(pre,0,sizeof(pre));//memset函数也会耗费很多时间
    int m_sum=0;
    for(int i=1;i<=m;i++)
    {
        m_sum=INF;
        for(int j=i;j<=n;j++)
        {
            cur[j]=max(cur[j-1],pre[j-1])+data[j];//pre此时存的是供这次用的
            pre[j-1]=m_sum;//把pre改成供下次用的
            m_sum=max(m_sum,cur[j]);
        }
        pre[n]=m_sum;
    }
    return m_sum;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF&&n&&m)
    {
        input();
        printf("%d\n",max_sum());
    }
    return 0;
}
