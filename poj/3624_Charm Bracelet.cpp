#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int f[13000];
int main()
{
	int n,m,w,d;
	while(cin>>n>>m)
	{
		memset(f,0,sizeof(f));
		for(int i=0;i<n;i++)
		{
			cin>>w>>d;
			for(int j=m;j>=w;j--)
			{
				f[j]=max(f[j],f[j-w]+d);
			}
		}
		cout<<f[m]<<endl;
	}
	return 0;
}