#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	string a,b;
	while(cin>>a>>b)
	{
		if(a!=b)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
