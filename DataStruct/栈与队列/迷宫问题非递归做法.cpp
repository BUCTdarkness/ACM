#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
char map[11][11];
int dir[4][2]={-1,0,0,-1,1,0,0,1};
bool iflegal(int x,int y)
{
	if(x>=0&&y>=0&&x<10&&y<10)
	{
		if(map[x][y]!='#'&&map[x][y]!='*'&&map[x][y]!='!')
			return true;
	}
	return false;
}
void print()
{
	for(int i=0;i<10;i++)
	{
		cout<<map[i]<<endl;
	}
}
void dfs(int x,int y)
{
	int u,ifl;
	u=x*10+y;
	stack <int> s;
	s.push(u);
	ifl=0;
	while(!s.empty())
	{
		u=s.top();
		x=u/10;
		y=u%10;
		if(map[x][y]=='E')
		{
			map[x][y]='*';
			return;
		}
		map[x][y]='*';
		ifl=0;
		for(int d=0;d<4;d++)
		{
			int sx=x+dir[d][0];
			int sy=y+dir[d][1];
			if(iflegal(sx,sy))
			{
				ifl=1;
				int v=sx*10+sy;
				s.push(v);
			}
		}
		if(ifl==0)
		{
			map[x][y]='!';
			s.pop();
		}
	}
}
int main()
{
	while(gets(map[0]))
	{
		for(int i=1;i<10;i++)
			gets(map[i]);
		int x,y;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				if(map[i][j]=='S')
				{
					x=i;
					y=j;
					break;
				}
			}
		dfs(x,y);
		print();
	}
	return 0;
} 

