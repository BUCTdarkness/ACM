#include<iostream>
#include<string.h>
using namespace std;
char map[11][11];
int flag=0;
int dir[4][2]={0,1,1,0,0,-1,-1,0};
int ans1,ans2;
bool iflegal(int x,int y)
{
	if(x>=0&&y>=0&&x<10&&y<10)
	{
		if(map[x][y]!='#'&&map[x][y]!='*'&&map[x][y]!='!')
			return true;
	}
	return false;
}
void dfs(int x,int y)
{
	if(map[x][y]=='E')
	{
		flag=1;
		map[x][y]='*';
		return;
	}
	int sx,sy;
	map[x][y]='*';
	int i;
	for(i=0;i<4;i++)
	{
		
		sx=x+dir[i][0];
		sy=y+dir[i][1];
		if(iflegal(sx,sy))
		{
			dfs(sx,sy);
			if(flag==1)
				break;
		}
	}
	if(i==4&&flag==0)
		map[x][y]='!';
}
void print()
{
	for(int i=0;i<10;i++)
	{
		cout<<map[i]<<endl;
	}
}
int main()
{
	while(gets(map[0]))
	{
		for(int i=1;i<10;i++)
			gets(map[i]);
		flag=0;
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
