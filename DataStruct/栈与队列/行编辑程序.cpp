#include<iostream>
#include<string.h>
#define MAX_LEN 300
using namespace std;
template<class T> 
class stack
{
	private:
		char data[MAX_LEN];
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
		void ClearStack()
		{
			this->len=0;
		}
		void print() const
		{
			for(int i=0;i<this->len;i++)
			{
				cout<<this->data[i];
			}
		}
		T top() const
		{
			return this->data[this->len-1];
		}
		bool isEmpty() const
		{
			if(this->len==0)
				return true;
			return false;
		}
	
};
void LineEdit()
{
	char ch;
	stack<char> s;
	ch=getchar();
	while(ch!=EOF)
	{
		while(ch!=EOF&&ch!='\n')
		{
			switch(ch)
			{
				case '#':
					s.pop();
					break;
				case '@':
					s.ClearStack();
					break;
				default:
					s.push(ch);
					break;
			}
			ch=getchar();
		}
		s.print();
		s.ClearStack();
		cout<<endl;
		if(ch!=EOF)
		{
			ch=getchar();
		} 
	}
}
int main()
{
	LineEdit();
	return 0;
}
