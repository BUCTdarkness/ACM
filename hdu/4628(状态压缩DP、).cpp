#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=(1<<16)+10;
const int INF=1<<30;
char s[20];
bool ok[MAXN];
int dp[MAXN];
int len,bit;
bool check(int x)
{
    if(x==0) return true;
    int i=0,j=len-1;
    while(i<j)
    {
         while(!(x&(1<<i))) i++;
         while(!(x&(1<<j))) j--;
         if(s[i]!=s[j])
            return false;
         i++;
         j--;
    }
    return true;
}
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>s;
            len=strlen(s);
            bit=1<<len;
            dp[bit-1]=0;
           // cout<<len<<" "<<bit<<endl;
            memset(ok,false,sizeof(ok));
            for(int i=0;i< bit;i++)
            {
                ok[i]=check(i);//改成check[i]居然也能编译通过。。。。真怀疑我是不是眼睛花了。。。
            }
            for(int i= bit-2;i>=0;i--)
            {
                dp[i]=INF;
                for(int j=i;j<bit;j=(j+1)|i)
                {
                    if(!ok[i^j]) continue;
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
            cout<<dp[0]<<endl;
        }
    }
    return 0;
}

