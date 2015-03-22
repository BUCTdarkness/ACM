#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const int MAX=1010;
const int M=10007;
int dp[MAX][MAX];
int main()
{
    int T;
    while(cin>>T)
    {
        for(int kase=1;kase<=T;kase++)
        {
            string s;
            cin>>s;
            memset(dp,0,sizeof(dp));
            for(int i=0;i<s.size();i++)
                dp[i][i]=1;
            for(int j=1;j<s.size();j++)
            {
                for(int i=j-1;i>=0;i--)
                {
                    dp[i][j]=(dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1]+M)%M;
                    if(s[i]==s[j])
                    {
                        dp[i][j]=(dp[i][j]+dp[i+1][j-1]+1+M)%M;
                    }
                }
            }
            cout<<"Case "<<kase<<": "<<dp[0][s.size()-1]<<endl;
        }
    }
    return 0;
}

