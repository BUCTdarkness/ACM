#include<iostream>
#include<string.h>
using namespace std;
#define MAX_LEN 150
template<class T>
class stack
{
	private:
		T data[MAX_LEN];
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
			{
				this->len--;
			}
		}
		T top() const
		{
			return this->data[len-1];
		}
		bool isEmpty()
		{
			if(this->len==0)
				return true;
			else
				return false;
		}
};
struct Pos
{
	char v;
	int pos;
};
Pos ch[101];
char ch1[101];
int yes[101];
int main()
{
	stack<Pos> s;
	while(gets(ch1))
	{
		cout<<ch1<<endl;
		memset(yes,0,sizeof(yes));
		int Len=strlen(ch1);
		for(int i=0;i<Len;i++)
		{
			ch[i].v=ch1[i];
			ch[i].pos=i;
		}
		for(int i=0;i<Len;i++)
		{
			if(ch[i].v=='(')
			{
				s.push(ch[i]);
			}
			if(ch[i].v==')')
			{
				Pos t=s.top();
				if(!s.isEmpty())
				{
					s.pop();
					yes[t.pos]=1;
					yes[ch[i].pos]=1;
				}
			}
		}
		while(!s.isEmpty())
		{
			s.pop();
		}
		for(int i=0;i<Len;i++)
		{
			if(ch[i].v=='('&&!yes[i])
			{
				cout<<"$";
			}
			else if(ch[i].v==')'&&!yes[i])
					{
						cout<<"?";
					}
				 else
				 	cout<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
