#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX=20+1;
char m[MAX][MAX];
int vis[MAX][MAX];
int w,h;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
bool ifleagl(int x,int y)
{
	if(x>=0&&y>=0&&x<w&&y<h&&!vis[x][y]&&m[x][y]!='#')
	{
		return true;
	}
	return false;
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int sx=x+dir[i][0];
		int sy=y+dir[i][1];
		if(ifleagl(sx,sy))
		{
			dfs(sx,sy);
		}
	}
}
int main()
{
	
	while(cin>>h>>w&&h&&w)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<w;i++)
		{
			cin>>m[i];
		}
		int bx,by;
		for(int i=0;i<w;i++)
			for(int j=0;j<h;j++)
			{
				if(m[i][j]=='@')
				{
					bx=i;
					by=j;
					break;
				}
			}
		dfs(bx,by);
		int ans=0;
		for(int i=0;i<w;i++)
			for(int j=0;j<h;j++)
			{
				if(vis[i][j])
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
