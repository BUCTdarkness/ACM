#include<iostream>
#include<string.h>
using namespace std;
char ch[1010];
char ch1[1010];
int main()
{
	while(gets(ch))
	{
		memset(ch1,'\0',sizeof(ch1));
		int len=strlen(ch);
		int k=0;
		for(int i=len-1;i>=0;i--)
			ch1[k++]=ch[i];
		if(strcmp(ch1,ch)==0)
		{
			cout<<"Yes!"<<endl;
		}
		else
			cout<<"No!"<<endl;
	}
	return 0;
}