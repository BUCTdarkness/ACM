#include<iostream>
#include<string.h>
#define MAX_LEN 110
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
bool isPushed[MAX_LEN];
int main()
{
	int N;
	int x;
	stack<int> s;
	while(cin>>N)
	{
		if(N==0)
			break;
		memset(isPushed,false,sizeof(isPushed)); 
		int flag=0;
		for(int i=0;i<N;i++)
		{
			cin>>x;
			for(int j=1;j<=x;j++)
			{
				if(isPushed[j]==false)
				{
					s.push(j);
					isPushed[j]=true;
				}
			}
			if(s.top()==x)
				s.pop();
			else
			{
				flag=1;
			}
		}
		while(!s.isEmpty())
			s.pop();
		if(flag==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
