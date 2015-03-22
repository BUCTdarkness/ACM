#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAX=4010;
int n;
int A[MAX],B[MAX],C[MAX],D[MAX];
int CD[MAX*MAX];
void solve()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			CD[i*n+j]=C[i]+D[j];
		}
	} 
	sort(CD,CD+n*n);
	__int64 res=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int cd=-(A[i]+B[j]);
			res+=upper_bound(CD,CD+n*n,cd)-lower_bound(CD,CD+n*n,cd);
		}
	cout<<res<<endl;
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++)
			{
				int x;
				scanf("%d",&x);
				if(j==0)
					A[i]=x;
				if(j==1)
					B[i]=x;
				if(j==2)
					C[i]=x;
				if(j==3)
					D[i]=x;
			}
		solve();
	}
	return 0;
}
