#include<iostream>
#include<cmath>
#include<cstdio>
#define MAXN 100100
#define EPS 1e-6
using namespace std;
int N;
double X[MAXN],Y[MAXN];
double F(double x1,double y1,double _x)
{
	return sqrt((_x-x1)*(_x-x1)+y1*y1);
}
double FF(double M)
{
	double ANS=0;
	for(int i=1;i<=N;i++)
	{
		if(fabs(Y[i])<EPS && fabs(X[i]-M)<EPS)
			continue;
		ANS+=F(X[i],Y[i],M);
	}
	return ANS;
}
double solve(double maxt,double mint)
{
	double L=mint,R=maxt;
	while(fabs(R-L)>EPS)
	{
		double M=(R+L)/2;
		double ANS1=FF(M),ANS2=FF(R);
		if(ANS1*ANS2>0)
		    R=M;
		else 
		    L=M;
	}
	return R;
}
int main()
{
	int T,kase=0;
	cin>>T;
	while(T--)
	{
		cin>>N;
		double maxt,mint;
		scanf("%lf%lf",&X[1],&Y[1]);
		maxt=X[1],mint=Y[1];
		for(int i=2;i<=N;i++)
		{
			scanf("%lf%lf",&X[i],&Y[i]);
			if(X[i]>maxt)
			    maxt=X[i];
			if(X[i]<mint)
			    mint=X[i];
		}
		if(FF(maxt)*FF(mint)>0)
	    {
	    	double dis1=DIS(maxt),dis2=DIS(mint);
	    	if(dis1<dis2)
	    	    printf("Case %d: %.6lf\n",++kase,maxt);
	    	else
	    	    printf("Case %d: %.6lf\n",++kase,maxt);
	    	continue;
	    }
		double ans=solve(maxt,mint);
		printf("Case %d: %.6lf\n",++kase,ans);
	}
}
