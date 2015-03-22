#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 51
#define INF 100000000
using namespace std; 
int G[maxn][maxn];
int n;
void read_graph()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>G[i][j];
			if(G[i][j]==0&&i!=j)
				G[i][j]=INF;
		}
}
void ShortestPath_FLOYD()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			{
				if(G[i][k]+G[k][j]<G[i][j])
					G[i][j]=G[i][k]+G[k][j];
			}
}
int main()
{
	while(cin>>n)
	{
		memset(G,0,sizeof(G));
		read_graph();
		ShortestPath_FLOYD();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(G[i][j]>=INF)
				{
					G[i][j]=-1;
				}
				cout<<G[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
