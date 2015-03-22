#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int m[6][6];
int ans=0;
int vis[1000000];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int make[6];
void dfs(int x,int y,int step)
{
    if(step==6)
    {
        int num=0;
        for(int i=0;i<6;i++)
        {
            num=num*10+make[i];
        }
        if(!vis[num])
        {
            ans++;
            vis[num]=1;
        }
        return;
    }
    make[step]=m[x][y];
    for(int i=0;i<4;i++)
    {
        int sx=x+dir[i][0];
        int sy=y+dir[i][1];
        if(sx>=0&&sx<5&&sy>=0&&sy<5)
            dfs(sx,sy,step+1);
    }
}
int main()
{
    ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>m[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dfs(i,j,0);
        }
    }
    cout<<ans<<endl;
    return 0;
}
