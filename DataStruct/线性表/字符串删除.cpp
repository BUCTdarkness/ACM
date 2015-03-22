#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char ch[100],s[3000];
	int change[3000];
	cin>>ch;
	getchar();
	while(gets(s))
	{
		memset(change,0,sizeof(change));
		int len1=strlen(ch);
		int len2=strlen(s);
		int j=0;
		for(int i=0;i<len1;i++)
		{
			if(ch[i]<='z'&&ch[i]>='a')
			{
				ch[i]+='A'-'a';
			}
		}
		for(int i=0;i<len2;i++)
		{
			if(s[i]<='z'&&s[i]>='a')
			{
				s[i]+='A'-'a';
				change[i]=1;
			}
		}
		j=0;
		for(int i=0;i<len2;i++)
		{
			int n=0;
			while(s[i+n]==ch[j]&&j<len1)
			{
				n++;
				j++;
			}
			if(j==len1)
			{
				j=0;
				i+=n-1;
				continue;
			}
			j=0;
			if(s[i]==' ')
			{
				continue;
			}
			if(change[i]==0)
				cout<<s[i];
			else
				printf("%c",s[i]-'A'+'a');
		}
		cout<<endl;
	}
	return 0;
}
