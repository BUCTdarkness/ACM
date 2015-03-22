#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX=1000010;
const int INF=1<<30;
int N,ML,MD;
int AL[MAX],BL[MAX],DL[MAX];
int AD[MAX],BD[MAX],DD[MAX];
int d[MAX];
void solve()
{
	for(int i=0;i<N;i++)
	{
		d[i]=INF;
	}
	d[0]=0;
	
	for(int k=0;k<N;k++)
	{
		for(int i=0;i+1<N;i++)
		{
			if(d[i+1]<INF)
				d[i]=min(d[i],d[i+1]);
		}
		for(int i=0;i<ML;i++)
		{
			if(d[AL[i]-1]<INF)
			{
				d[BL[i]-1]=min(d[BL[i]-1],d[AL[i]-1]+DL[i]);
			}
		}
		for(int i=0;i<MD;i++)
		{
			if(d[BD[i]-1]<INF)
			{
				d[AD[i]-1]=min(d[AD[i]-1],d[BD[i]-1]-DD[i]);
			}
		}
	}
	int res=d[N-1];
	if(d[0]<0)
	{
		res=-1;
	}
	else if(res==INF)
	{
		res=-2;
	}
	cout<<res<<endl;
}
int main(void)
{
	while(cin>>N>>ML>>MD)
	{
		for(int i=0;i<ML;i++)
		{
			cin>>AL[i]>>BL[i]>>DL[i];
		}
		for(int i=0;i<MD;i++)
		{
			cin>>AD[i]>>BD[i]>>DD[i];
		}
		solve();
	}
	return 0;
}

