#include<iostream>
#include<string.h>
#define MAX_LEN 200
#define OPSETSIZE 7
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
		void ClearStack()
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
unsigned char Prior[7][7]=
{
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=',' '},
	{'>','>','>','>',' ','>','>'},
	{'<','<','<','<','<',' ','='}
};
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};
bool InOPSET(char c)
{
	for(int i=0;i<OPSETSIZE;i++)
	{
		if(OPSET[i]==c)
		{
			return true;
		}
	}
	return false;
}
int p(char c)
{
	if(c=='+')
		return 0;
	if(c=='-')
		return 1;
	if(c=='*')
		return 2;
	if(c=='/')
		return 3;
	if(c=='(')
		return 4;
	if(c==')')
		return 5;
	if(c=='#')
		return 6;
}
int EvaluateExpression(char *MyExpression)
{
	stack<char> OPTR;
	stack<int> OPND;
	char TempData[20];
	int Data,a,b;
	char *c,Dr[2];
	int x,theta;
	OPTR.push('#');
	c=MyExpression;
	strcpy(TempData,"\0");
	while(*c!='#'||OPTR.top()!='#')
	{
		if(!InOPSET(*c))
		{
			Dr[0]=*c;
			Dr[1]='\0';
			strcat(TempData,Dr);
			c++;
			if(InOPSET(*c))
			{
				Data=atoi(TempData);
				OPND.push(Data);
				strcpy(TempData,"\0");
			}
		}
		else
		{
			char ss=Prior[p(OPTR.top())][p(*c)];
			switch(ss)
			{
			case '<':
					OPTR.push(*c);
					c++;
					break;
			case '=':
					OPTR.pop();
					c++;
					break;
					
			case '>':
					int a=OPND.top();
					OPND.pop();
					int b=OPND.top();
					OPND.pop();
					char k=OPTR.top();
					OPTR.pop();
					int s;
					if(k=='+')
						s=a+b;
					if(k=='-')
						s=b-a;
					if(k=='*')
						s=a*b;
					if(k=='/')
						s=b/a;
					OPND.push(s);
			}
		}
	}
	return OPND.top();
}
int main()
{
	char s[1000];
	while(cin>>s)
	{
		s[strlen(s)]='#';
		cout<<EvaluateExpression(s)<<endl;
	}
	return 0;
}