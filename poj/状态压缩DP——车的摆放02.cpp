#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef unsigned long long ll;
ll f[1<<21];
 int main()
 {
 	ll n;
 	while(cin>>n)
 	{
 		int a[21]={0};
	 	int m;
	 	cin>>m;
	 	for(ll i=0;i<n;i++)
	 	{
	 		a[i]=(1<<n)-1;
	 	}
	 	for(int i=0;i<m;i++)
	 	{
	 		int x,y;
	 		cin>>x>>y;
	 		a[x]-=1<<y;
	 	}
	 	memset(f,0,sizeof(f));
	 	f[0]=1;
	 	for(ll i=1;i<(1<<n);i++)
	 	{
			int k=0;
			ll tmp=i;
			for(k=0;tmp>0;k++)
				tmp-=tmp&(-tmp); //算出有几个1，其实也就是第几行
 			for(int j=i&a[k-1];j>0;j-=(j&(-j)))
		 	{
 				f[i]+=f[i&(~(j&(-j)))];
 			}	
	 	} 
	 	cout<<f[(1<<n)-1]<<endl;
 	}
 	return 0;
 }
 