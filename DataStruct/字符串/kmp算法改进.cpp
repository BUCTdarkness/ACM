//??????KMP?? 
//kmp (1) i 指针不回溯 （2）j重新定位 
//ababcababab
//01123123454 

//改进kmp 
// original : aaaaaaab
//模式串：aaaab 

#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_LEN 110
using namespace std;
void getnext(char *p,int *next)
{
	int len=strlen(p);
	next[0]=0;
	next[1]=0;
	for(int i=1;i<len;i++)
	{
		int j=next[i];
		while(j&&p[i]!=p[j])
		{
			j=next[j];
		}
		next[i+1]=p[i]==p[j]?j+1:0;
	}
//	for(int i=0;i<len;i++)
//		cout<<next[i]<<" ";
}
void getnextval(char *p,int *nextval,int *next)
{
	int len=strlen(p);
	nextval[0]=0;
	nextval[1]=0;
	for(int i=2;i<len;i++)
	{
		int k=next[i];
		if(p[i]==p[k])
			nextval[i]=next[k];
		else
			nextval[i]=next[i];
	}
}
int kmpfind(char *t,char *p,int *next,int *nextval)
{
	int len1=strlen(t);
	int len2=strlen(p);
	int j=0;
	getnext(p,next);
	getnextval(p,next,nextval);
	for(int i=0;i<len2;i++)
	{
		cout<<nextval[i]<<" ";
	}
	for(int i=0;i<len1;i++)
	{
		while(j&&t[i]!=p[j])
		{
			j=nextval[j];
		}
		if(t[i]==p[j])
		{
			j++;
		}
		if(j==len2)
		{
			return i-len2+2;
		} 
	}
	return 0;
}
int main()
{
	int next[MAX_LEN],nextval[MAX_LEN];
	char p[MAX_LEN],t[MAX_LEN];
	while(cin>>t>>p)
	{
		memset(next,0,sizeof(next));
		memset(nextval,0,sizeof(nextval));
		cout<<kmpfind(t,p,next,nextval)<<endl;
	}
	return 0;
}
