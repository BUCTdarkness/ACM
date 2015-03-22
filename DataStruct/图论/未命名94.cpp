#include<iostream>
#include<cstring>
#define MAXN 20
using namespace std;
int dis[MAXN][MAXN],n;
int main()
{
	while(cin>>n)
	{
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)
		        cin>>dis[i][j];
		for(int p=1;p<=n;p++)
		{
			for(int i=1;i<=n;i++)
			{
			    if(i==p || dis[i][p]==-1)
		            continue;
		        for(int j=0;j<=n;j++)
		        {
		        	if(dis[p][j]==-1 || p==j)
		        	    continue;
		        	dis[i][j]=min(dis[i][j],dis[i][p]+dis[p][j]);
		            if(dis[i][j]==-1)
		                dis[i][j]=dis[i][p]+dis[p][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			cout<<dis[i][1];
			for(int j=2;j<=n;j++)
			    cout<<' '<<dis[i][j];
			cout<<endl;
		}
	}
	return 0;
}