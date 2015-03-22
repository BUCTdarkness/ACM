#include<iostream>
#include<cstring>
#define MAX_LEN 100
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int c[MAX_LEN];
		for(int i=0;i<n;i++)
		{
			c[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<"sss"<<endl;
			cout<<x<<" "<<y<<endl;
			c[x]=c[y]+1;
		}
		cout<<c[1]<<endl;
		cout<<c[2]<<endl;
	}
	return 0;
}
