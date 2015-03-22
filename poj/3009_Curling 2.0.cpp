#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX=30;
int ans;
int m[MAX][MAX];
int w,h;
int bx,by;
void dfs(int i,int j,bool status,int direction,int step,bool flag)
{
	if(step>10)
		return;
	if(m[i][j]==3)
	{
		ans=min(ans,step);
		return;
	}
	if(flag)
	{
		switch(direction)
		{
			case 0:
			{
				m[i-1][j]=0;
				break;
			}
			case 1:
			{
				m[i][j-1]=0;
				break;
			}
			case 2:
			{
				m[i+1][j]=0;
				break;
			}
			case 3:
			{
				m[i][j+1]=0;
				break;
			}
		}
	}
	if(!status)
	{
		if(i-1>=0&&(m[i-1][j]==0||m[i-1][j]==3))
			dfs(i-1,j,true,0,step+1,false);
		if(j-1>=0&&(m[i][j-1]==0||m[i][j-1]==3))
			dfs(i,j-1,true,1,step+1,false);
		if(i+1<h&&(m[i+1][j]==0||m[i+1][j]==3))
			dfs(i+1,j,true,2,step+1,false);
		if(j+1<w&&(m[i][j+1]==0||m[i][j+1]==3))
			dfs(i,j+1,true,3,step+1,false);
	}
	else if(status)
	{
		switch(direction)
		{
			case 0:
			{
				if(i-1<0)
					return;
				else
				{
					if(m[i-1][j]==0)
					{
						dfs(i-1,j,true,0,step,false);
					}
					else if(m[i-1][j]==1)
					{
						dfs(i,j,false,0,step,true);
					}
					else if(m[i-1][j]==3)
					{
						dfs(i-1,j,false,0,step,false);
					}
				}
				break;
			}
			case 1:
			{
				if(j-1<0)
					return;
				else
				{
					if(m[i][j-1]==0)
					{
						dfs(i,j-1,true,1,step,false);
					}
					else if(m[i][j-1]==1)
					{
						dfs(i,j,false,1,step,true);
					}
					else if(m[i][j-1]==3)
					{
						dfs(i,j-1,false,1,step,false);
					}
				}
				break;
			}
			case 2:
			{
				if(i+1>=h)
					return;
				else
				{
					if(m[i+1][j]==0)
					{
						dfs(i+1,j,true,2,step,false);
					}
					else if(m[i+1][j]==1)
					{
						dfs(i,j,false,2,step,true);
					}
					else if(m[i+1][j]==3)
					{
						dfs(i+1,j,false,2,step,false);
					}
				}
				break;
			}
			case 3:
			{
				if(j+1>=w)
					return;
				else
				{
					if(m[i][j+1]==0)
					{
						dfs(i,j+1,true,3,step,false);
					}
					else if(m[i][j+1]==1)
					{
						dfs(i,j,false,3,step,true);
					}
					else if(m[i][j+1]==3)
					{
						dfs(i,j+1,false,3,step,false);
					}
				}
				break;
			}
		}
	}
	if(flag)
	{
		switch(direction)
		{
			case 0:
			{
				m[i-1][j]=1;
				break;
			}
			case 1:
			{
				m[i][j-1]=1;
				break;
			}
			case 2:
			{
				m[i+1][j]=1;
				break;
			}
			case 3:
			{
				m[i][j+1]=1;
				break;
			}
		}
	}
	return;
}
int main()
{
	while(cin>>w>>h)
	{
		if(!w&&!h) break;
		memset(m,0,sizeof(m));
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				cin>>m[i][j];
			}
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				if(m[i][j]==2)
				{
					bx=i;
					by=j;
					m[i][j]=0;
				}
			}
		ans=11;
		dfs(bx,by,false,0,0,false);
		if(ans<=10)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;	
}
