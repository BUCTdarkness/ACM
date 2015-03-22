#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=51;
int edge[maxn][maxn];
int c[maxn];
void TopoOrder(int n)
{
	int top=-1;
	for(int i=0;i<n;++i)
		if(c[i]==0)
		{
			c[i]=top;
			top=i;
		}
	for(int i=0;i<n;++i)
	{
		if(top==-1)
		{
			cout<<"ERROR"<<endl;
			return;
		}
		else
		{
			int j=top;
			top=c[top];
			cout<<j<<" ";
			for(int k=0;k<n;k++)
			{
				if(edge[j][k]&&(--c[k])==0)
				{
					c[k]=top;
					top=k;
				}
			}
		}
	}
}
int main()
{
	int n;
	while(cin>>n)
	{
		memset(edge,0,sizeof(edge));
		memset(c,0,sizeof(c));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				cin>>edge[i][j];
			}
		TopoOrder(n);
		cout<<endl;
	}
	return 0;
}
