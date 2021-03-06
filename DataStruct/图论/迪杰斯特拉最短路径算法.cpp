#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 100000000
using namespace std;
void read_graph(int w[][51],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>w[i][j];
			if(w[i][j]==0)
				w[i][j]=INF;
		}
}
int main()
{
	int n,s;
	int w[51][51];
	int d[51];
	int v[51];
	while(cin>>n>>s)
	{
		memset(w,0,sizeof(w));
		memset(v,0,sizeof(v));
		read_graph(w,n);
		for(int i=0;i<n;i++)
			d[i]=(i==s?0:INF);
		for(int i=0;i<n;i++)
		{
			int x,m=INF;
			for(int y=0;y<n;y++)
			{
				if(!v[y]&&d[y]<=m)
				{
					m=d[x=y];
				}
			}
			v[x]=1;
			for(int y=0;y<n;y++)
				d[y]=min(d[x]+w[x][y],d[y]);
		}
		for(int i=0;i<n;i++)
		{
			if(i==s) continue;
			if(d[i]>=INF)
				cout<<-1<<" ";
			else
				cout<<d[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
