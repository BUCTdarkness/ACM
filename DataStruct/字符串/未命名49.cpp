#include<iostream>
#include<string.h>
using namespace std;
int index(char *s,char *t)
{
	int i=0;
	int j=0;
	int len1=strlen(s);
	int len2=strlen(t);
	while(i<len1&&j<len2)
	{
		cout<<s[i];
		if(s[i]==t[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	cout<<endl;
	if(j==len2)
		return i-len2+1;
	else
		return 0;
}
int main()
{
	char ch1[110],ch2[110];
	memset(ch1,'\0',sizeof(ch1));
	memset(ch2,'\0',sizeof(ch2));
	while(cin>>ch1>>ch2)
	{
		cout<<index(ch1,ch2)<<endl;
		memset(ch1,'\0',sizeof(ch1));
		memset(ch2,'\0',sizeof(ch2));
	}
	return 0;
}
