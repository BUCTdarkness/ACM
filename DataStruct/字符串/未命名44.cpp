#include<iostream>
using namespace std;
int main()
{
	char s[1010];
	while(cin>>s&&s[0]!='#')
	{
		int num=0;
		for(int i=0;i<strlen(s)-1;i++)
		{
			if(s[i]=='1')
			{
				num++;
			}
		}
		if(s[strlen(s)-1]=='e')
		{
			if(num%2==0)
			{
				s[strlen(s)-1]='0';
			}
			else
				s[strlen(s)-1]='1';
		}
		else
		{
			if(num%2==0)
			{
				s[strlen(s)-1]='1';
			}
			else
				s[strlen(s)-1]='0';
		}
		cout<<s<<endl;
	}
	return 0;
}