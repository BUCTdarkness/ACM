#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s1[500],s2[200];
	int n;
	while(cin>>s1>>s2>>n)
	{
		int len1=strlen(s1);
		int len2=strlen(s2);
		for(int i=len1-1;i>=n-1;i--)
		{
			s1[i+len2]=s1[i];
		}
		for(int i=0;i<len2;i++)
		{
			s1[n-1+i]=s2[i];
		}
		cout<<s1<<endl;
	}
	return 0;
}
