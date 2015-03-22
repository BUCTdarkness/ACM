#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int f[1010][1010];
unsigned long long t[1010][1010];
int main()
{
	int n;
	int rmb[101];
	int rp[101];
	int time[101];
	int m,r;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>rmb[i]>>rp[i]>>time[i];
		}
		cin>>m>>r;
		for(int i=0;i<n;i++)
		{
			for(int j=m;j>=rmb[i];j--)
			{
				for(int k=r;k>=rp[i];k--)
				{
					if(f[j][k]<f[j-rmb[i]][k-rp[i]]+1)
					{
						f[j][k]=f[j-rmb[i]][k-rp[i]]+1;
						t[j][k]=t[j-rmb[i]][k-rp[i]]+time[i];
					}
					else if(f[j][k]==f[j-rmb[i]][k-rp[i]]+1)
					{
						t[j][k]=min(t[j][k],t[j-rmb[i]][k-rp[i]]+time[i]);
					}
				}
			}
		}
		cout<<t[m][r]<<endl;
	}
	return 0;
}
