#include<iostream>
#include<string.h>
using namespace std;
char ch[1010];
char c[3];
int main()
{
	while(gets(ch))
	{
		gets(c);
		for(int i=0;i<strlen(ch);i++)
		{
			if(ch[i]!=c[0])
				cout<<ch[i];
		}
		cout<<endl;
	}
	return 0;
}