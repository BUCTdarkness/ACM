#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int MAX_K=300010;
int N,K;
int T[MAX_K],X[MAX_K],Y[MAX_K];
int par[MAX_K];
int ran[MAX_K];
void init()
{
	for(int i=0;i<MAX_K;i++)
	{
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}
bool same(int a,int b)
{
	return find(a)==find(b);
}
void unite(int a,int b)
{
	int x=find(a);
	int y=find(b);
	if(x==y)
		return;
	if(ran[x]<ran[y])
	{
		par[x]=y;
	}
	else
	{
		par[y]=x;
		if(ran[x]==ran[y])
			ran[x]++;
	}
}
void solve()
{
	init();
	int ans=0;
	for(int i=0;i<K;i++)
	{
		int t=T[i];
		int x=X[i]-1;
		int y=Y[i]-1;
		if(x<0||x>=N||y<0||y>=N)
		{
			ans++;
			continue;
		}
		if(t==1)
		{
			if(same(x,y+N)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y);
				unite(x+N,y+N);
				unite(x+N*2,y+N*2);
			}
		}
		else
		{
			if(same(x,y)||same(x,y+2*N))
			{
				ans++;
			}
			else
			{
				unite(x,y+N);
				unite(x+N,y+2*N);
				unite(x+2*N,y);
			}
		}
	}
	cout<<ans<<endl;
}
int main(void)
{
	while(cin>>N>>K)
	{
		memset(T,0,sizeof(T));
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		for(int i=0;i<K;i++)
		{
			cin>>T[i]>>X[i]>>Y[i];
		}
		solve();
	}
	return 0;
}

