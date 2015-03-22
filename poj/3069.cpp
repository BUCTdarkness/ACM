#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int r,n,x[1010];
	while(cin>>r>>n&&r!=-1&&n!=-1)
	{
		for(int i=0;i<n;i++)
			cin>>x[i];
		sort(x,x+n);
		int i=0;
		int ans=0;
		while(i<n)
		{
			int s=x[i++];
			while(i<n&&x[i]<=s+r) i++;
			int p=x[i-1];
			while(i<n&&x[i]<=p+r) i++;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
