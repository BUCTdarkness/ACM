#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int main()
{
	string ch;
	int n,s,U,I,m;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>ch;
			I=0;
			U=0;
			m=0;
			if(ch[0]!='M')
			{
				cout<<"No"<<endl;
				continue;
			}
			for(int i=1;i<ch.size();i++)
			{
				if(ch[i]=='M')
				{
					m=1;
					break;
				}
				else
				if(ch[i]=='I')
				{
					I++;
				}
				else
				if(ch[i]=='U')
				{
					U++;
				}
			}
			if(m==1||(I%3==0)||((U+I)%2==1&&!(I==1&&U==0)))
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}