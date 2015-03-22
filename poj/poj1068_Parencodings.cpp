#include<iostream>
#include<stack>
using namespace std;
struct Paren
{
	char ch;
	int num;
};
int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
		{
			int n;
			cin>>n;
			stack<Paren> p;
			Paren x;
			for(int i=0;i<n;i++)
			{
				cin>>x.ch;
				x.num=0;
				if(x=='(')
				{
					
				}
			}
		}
	}
}
