//两个二进制数j 和-j
//j^-j将得到最低位1的位置 
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
typedef unsigned long long ll;
ll f[1100000];
int main()
{
	ll n;
	while(cin>>n)
	{
		memset(f,0,sizeof(f));
		f[0]=1;
		ll i,j;
		for(i=1;i< 1<<n;i++)
		{
			for(j=i;j>0;j-=(j&-j))//不断的把最低位的1扣掉 
			{
				f[i]+=f[i&~(j&-j)];
			}
		}
		cout<<f[(1<<n)-1]<<endl;
	}
	return 0;	
}
