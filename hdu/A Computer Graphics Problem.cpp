#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		for(int i=1;i<=t;i++)
		{
			int n;
			cin>>n;
			cout<<"Case #"<<i<<":"<<endl;
			cout<<"*------------*"<<endl;
			for(int j=0;j<((100-n)/10);j++)
			{
				cout<<"|............|"<<endl;
			}
			for(int j=0;j<(n/10);j++)
			{
				cout<<"|------------|"<<endl;
			}
			cout<<"*------------*"<<endl;
		}
	}
	return 0;
}
