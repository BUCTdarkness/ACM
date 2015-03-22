#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAX=205;
int dp[MAX][MAX];
char s1[MAX];
char s2[MAX];
void solve()
{
    int len1=strlen(s1);
    int len2=strlen(s2);
    for(int i=0;i<=len2;i++)
    {
        dp[0][i]=i;
    }
    for(int i=0;i<=len1;i++)
    {
        dp[i][0]=i;
    }
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            int temp;
            if(s1[i-1]==s2[j-1])
            {
                temp=dp[i-1][j-1];
            }
            else
            {
                temp=dp[i-1][j-1]+1;
            }
            temp=min(temp,dp[i][j-1]+1);
            temp=min(temp,dp[i-1][j]+1);
            dp[i][j]=temp;
        }
    }
    cout<<dp[len1][len2]<<endl;
}
int main()
{
    while(gets(s1))
    {
        gets(s2);
        solve();
    }
    return 0;
}
