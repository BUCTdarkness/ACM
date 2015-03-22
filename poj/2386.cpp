#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int maxn =101;
char f[maxn][maxn];
void dfs(int x,int y)
{
    f[x][y]='.';
    for(int dx=-1;dx<=1;dx++)
        for(int dy=-1;dy<=1;dy++)
    {
        int nx=x+dx;
        int ny=y+dy;
        if(0<=nx&&nx<n&&0<=ny&&ny<m&&f[nx][ny]=='W')
                dfs(nx,ny);
    }
    return ;
}
void solve()
{
    int res=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
    {
        if(f[i][j]=='W')
        {
            dfs(i,j);
            res++;
        }
    }
    cout<<res<<endl;
}
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            cin>>f[i];
        solve();
    }
    return 0;
}
