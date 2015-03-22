#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAX=30;
int g[MAX][MAX];
int vis[MAX];
bool flag=false;
void dfs(int u)
{
    if(u+'a'=='m')
    {
        flag=true;
        return ;
    }
    for(int v=0;v<26;v++)
    {
        if(g[u][v]&&!flag)
        {
            if(!vis[v])
            {
                vis[v]=1;
                dfs(v);
                vis[v]=0;
            }
        }
    }
}
int main()
{
    string s;
    memset(g,0,sizeof(g));
    memset(vis,0,sizeof(vis));
    while(cin>>s)
    {
        if(s[0]=='0')
        {
            vis[1]=0;
            flag=false;
            dfs(1);
            if(flag)
            {
                cout<<"Yes."<<endl;
            }
            else
            {
                cout<<"No."<<endl;
            }
            memset(vis,0,sizeof(vis));
            memset(g,0,sizeof(g));
        }
        else
        {
            int len=s.size();
            g[s[0]-'a'][s[len-1]-'a']=1;
        }
    }
    return 0;
}

