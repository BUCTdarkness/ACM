#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=(1<<15)-1;
int N,C;
int L[MAX],S[MAX],A[MAX];
double vx[MAX],vy[MAX];
int ang[MAX];
double prv[MAX];
void init(int k,int l,int r)
{
	ang[k]=vx[k]=0.0;
	if(r-1==l)
	{
		vy[k]=L[l];
	}
	else
	{
		int chl=k*2+1;
		int chr=k*2+2;
		init(chl,l,(l+r)/2);
		init(chr,(l+r)/2,r);
		vy[k]=vy[chl]+vy[chr];
	}
}
void update(int s,double a,int v,int l,int r)
{
	if(s<=l)
		return;
	else if(s<r)
	{
		int chl=v*2+1,chr=v*2+2;
		int m=(l+r)/2;
		update(s,a,chl,l,m);
		update(s,a,chr,m,r);
		if(s<=m)
			ang[v]+=a;
		double s=sin(ang[v]),c=cos(ang[v]);
		vx[v]=vx[chl]+(c*vx[chr]-s*vy[chr]);
		vy[v]=vy[chl]+(s*vx[chr]+c*vy[chr]);
	}
}
void solve()
{
	init(0,0,N);
	for(int i=1;i<N;i++)
		prv[i]=M_PI;
	for(int i=0;i<C;i++)
	{
		int s=S[i];
		double a=A[i]/360.0*2*M_PI;
		update(s,a-prv[s],0,0,N);
		prv[s]=a;
		printf("%.2f %.2f\n",vx[0],vy[0]);
	}
}
int main()
{
	while(cin>>N>>C)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%d",&L[i]);
		}
		for(int i=0;i<C;i++)
		{
			scanf("%d%d",&S[i],&A[i]);
		}
		solve();
	}
	return 0;
}
