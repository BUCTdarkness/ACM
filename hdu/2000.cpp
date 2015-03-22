#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	char a[10];
	while(cin>>a)
	{
		sort(a,a+3);
		for(int i=0;i<3;i++)
		{
			if(i!=0)
				cout<<" ";
			cout<<a[i];
		}
		cout<<endl;
	}
	return 0;
}
