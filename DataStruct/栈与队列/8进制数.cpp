#include<iostream>
#include<stack>
using namespace std;
void conversion(int num)
{
	stack<int> s;
	while(num)
	{
		s.push(num%8);
		num=num/8;
	}
	while(!s.empty())
	{
		int x;
		x=s.top();
		s.pop();
		cout<<x;
	}
	cout<<endl;
}
int main()
{
	stack<int> s;
	int x;
	while(cin>>x)
	{
		if(x==0)
		{
			cout<<0<<endl;
			continue;
		}
		conversion(x);
	}
	return 0;
}