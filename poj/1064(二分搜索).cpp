#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=10010;
const int INF=1000000001;
int N,K;
double L[MAXN];
bool C(double x)
{
	int num=0;
	for(int i=0;i<N;i++)
	{
		num+=(int)(L[i]/x);
	}
	return num>=K;
}
void solve()
{
	double lb=0;
	double ub=INF;
	for(int i=0;i<100;i++)
	{
		double mid=(lb+ub)/2;
		if(C(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%.2f\n",floor(lb*100)/100);
}
int main(void)
{
	while(cin>>N>>K)
	{
		for(int i=0;i<N;i++)
		{
			scanf("%lf",&L[i]);
		}
		solve();
	}
	return 0;
}

