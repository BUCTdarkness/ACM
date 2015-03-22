#include<iostream>
#include<string.h>
using namespace std;
void getfail(char *p,int *f)
{
	int len=strlen(p);
	f[0]=0;
	f[1]=0;
	for(int i=1;i<len;i++)
	{
		int j=f[i];
		while(j&&p[i]!=p[j])
			j=f[j];
		f[i+1]=(p[i]==p[j])?j+1:0;
	}
}
int kmp(char *t,char *p,int *f)
{
	int len1=strlen(t);
	int len2=strlen(p);
	getfail(p,f);
	int j=0;
	for(int i=0;i<len1;i++)
	{
		while(j&&p[j]!=t[i])
			j=f[j];
		if(p[j]==t[i])
			j++;
		if(j==len2)
		{
			return i-len2+2;
		}
	}
	return 0;
}
char ch1[20000005],ch2[20000005];
int f[20000005];
int main()
{
	while(cin>>ch1>>ch2)
	{
		memset(f,0,sizeof(f));
		cout<<kmp(ch1,ch2,f)-1<<endl;
	}
	return 0;
}
