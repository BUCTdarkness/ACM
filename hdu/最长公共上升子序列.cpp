#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=1010;
char str1[MAXN],str2[MAXN];
int dp[MAXN][MAXN];
void change(char *s,int len)
{
    for(int i=len;i>0;i--)
    {
        s[i]=s[i-1];
    }
    s[len+1]='\0';
}
int main()
{
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        int len1=strlen(str1);
        int len2=strlen(str2);
        change(str1,len1);
        change(str2,len2);
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(str1[i]==str2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}

