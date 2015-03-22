#include<iostream>
using namespace std;
int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
		{
			double a,b,c;
			cin>>a>>b>>c;
		//	cout<<"ss";
			if(a>0&&b>0&&c>0)
			{
				if(a+b>c&&a+c>b&&b+c>a)
				{
					cout<<"YES"<<endl;
				}
				else
				{
					cout<<"NO"<<endl;
				}
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}	
	return 0;
}