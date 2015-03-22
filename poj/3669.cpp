#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAX=400;
struct Point
{
    int x,y,t;
};
int m;
int mp[MAX][MAX];
int vis[MAX][MAX];
int dir[4][2]={-1,0,0,1,1,0,0,-1};
void BFS()
{
    queue<Point> q;
    q.push({0,0,0});
    vis[0][0]=1;
    while(!q.empty())
    {
        Point p=q.front();
        q.pop();
        if(mp[p.x][p.y]==-1)
        {
            cout<<p.t<<endl;
            return;
        }
        for(int i=0;i<4;i++)
        {
            int sx=p.x+dir[i][0];
            int sy=p.y+dir[i][1];
            if(sx>=0&&sy>=0&&!vis[sx][sy])
            {
                if(p.t+1<mp[sx][sy]||mp[sx][sy]==-1)
                {
                    q.push({sx,sy,p.t+1});
                    vis[sx][sy]=1;
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main()
{
    while(cin>>m)
    {
        memset(mp,-1,sizeof(mp));
        memset(vis,0,sizeof(vis));
        while(m--)
        {
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            if(mp[x][y]==-1)
            {
                mp[x][y]=t;
            }
            else
            {
                mp[x][y]=min(mp[x][y],t);
            }
            for(int i=0;i<4;i++)
            {
                int sx=x+dir[i][0];
                int sy=y+dir[i][1];
                if(sx>=0&&sy>=0)
                {
                    if(mp[sx][sy]==-1)
                    {
                        mp[sx][sy]=t;
                    }
                    else
                    {
                        mp[sx][sy]=min(mp[sx][sy],t);
                    }
                }
            }
        }
        BFS();
    }
    return 0;
}

