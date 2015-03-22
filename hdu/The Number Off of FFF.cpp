#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		for(int k=1;k<=t;k++)
		{
			int n,ans,flag=0,t=0;
			int m;
			int p;
			cin>>n;
			cin>>m;
			p=m;
			for(int i=2;i<=n;i++)
			{
				cin>>m;
				if(flag==0)
				{
					if(m!=p+1)
					{
						ans=i;
						flag=1;
						t=1;
					}
					p=m;
				}
			}
			if(t==0) cout<<"Case #"<<k<<": "<<1<<endl;
			else
			cout<<"Case #"<<k<<": "<<ans<<endl;
		}
	}
	return 0;
}