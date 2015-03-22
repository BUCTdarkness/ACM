#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n,a[1010];
	while(cin>>n)
	{
		int flag=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n+1;i++)
		{
			cin>>a[i];
		}
		for(int i=2;i<=n+1;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(a[j]==a[i])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
			{
				cout<<a[i]<<endl;
				break;
			}
		}
	}
	return 0;
}