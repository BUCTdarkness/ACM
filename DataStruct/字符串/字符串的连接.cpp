#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char ch1[110],ch2[110];
	while(cin>>ch1>>ch2)
	{
		if(strlen(ch1)+strlen(ch2)>100)
		{
			cout<<"Result String is cutted."<<endl;
		}
		else
		{
			cout<<ch1<<ch2<<endl;
		}
	}
	return 0;
}