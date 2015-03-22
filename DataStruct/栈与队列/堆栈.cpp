#include<iostream>
#include<string.h>
#define MAX_LEN 10500
using namespace std;
template<class T> 
class stack
{
	private:
		int data[MAX_LEN];
		int len;
	public:
		stack()
		{
			this->len=0;
		}
		void push(T t)
		{
			this->data[this->len]=t;
			this->len++; 
		}
		void pop()
		{
			if(this->len>0)
				this->len--; 
		}
		void clearStack()
		{
			this->len=0;
		}
		T top() const
		{
			return this->data[this->len-1];
		}
		bool isEmpty()
		{
			if(this->len==0)
				return true;
			return false;
		}
	
};
int main()
{
	int n;
	stack<int> s;
	while(cin>>n)
	{
		if(n==0)
			break;
		while(n--)
		{
			char ch;
			getchar();
			cin>>ch;
			if(ch=='P')
			{
				int x;
				cin>>x;
				s.push(x);
			}
			if(ch=='O')
			{
				s.pop();
			}
			if(ch=='A')
			{
				if(!s.isEmpty())
				{
					cout<<s.top()<<endl;
				}
				else
					cout<<"E"<<endl;
			}
		}
		cout<<endl;
		s.clearStack();
	}
	return 0;
}