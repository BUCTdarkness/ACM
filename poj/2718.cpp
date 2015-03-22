#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int INF=0x7fffffff;
int la;
int a[20],vis[20],b[20],ans;
void solve(int s1)
{
    int lb=0,s2=0;
    for(int i=0;i<la;i++)
    {
        if(!vis[i])
        {
            b[lb++]=a[i];
        }
    }
    for(int i=0;i<lb;i++)
    {
        s2=s2*10+b[i];
    }
    if(b[0]!=0||lb==1)
        ans=min(ans,abs(s1-s2));
    while(next_permutation(b,b+lb))
    {
        s2=0;
        for(int i=0;i<lb;i++)
        {
            s2=s2*10+b[i];
        }
        if(b[0]!=0)
            ans=min(ans,abs(s1-s2));
    }
}
void dfs(int len,int s1)
{
    if(len==la/2)
    {
        solve(s1);
        return;
    }
    for(int i=0;i<la;i++)
    {
        if(vis[i])
            continue;
        if(a[i]==0&&la>3)
            continue;
        vis[i]=1;
        dfs(len+1,s1*10+a[i]);
        vis[i]=0;
    }

}
int main()
{
    int kase;
    cin>>kase;
    getchar();
    while(kase--)
    {
        char s[20];
        memset(vis,0,sizeof(vis));
        gets(s);
        la=0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                 a[la++]=s[i]-'0';
            }
        }
        ans=INF;
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}

