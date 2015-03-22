#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	int n,s;

	while(cin>>n>>s)
	{
		__int64 sum=0;
		int minc=1000000;
		while(n--)
		{
			int c,y;
			cin>>c>>y;
			minc=min(minc+s,c);	
			sum+=minc*y;
		}
		cout<<sum<<endl;
	}
	return 0;
}
