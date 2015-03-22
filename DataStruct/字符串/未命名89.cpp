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
	next[0]=-1;
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
	for(int i=0;i<len;i++)
	{
		cout<<next[i];
		if(i!=len-1)
			cout<<" ";
	}
	cout<<endl;
}
void getnextval(char *p,int *nextval,int *next)
{
	
	int len=strlen(p);
		for(int i=0;i<len;i++)
	{
		cout<<next[i];
		if(i!=len-1)
			cout<<" ";
	}
	cout<<endl;
	nextval[0]=-1;
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
int kmpfind(char *p,int *next,int *nextval)
{
	int len=strlen(p);
	getnext(p,next);
	getnextval(p,nextval,next);
	for(int i=0;i<len;i++)
	{
		cout<<nextval[i];
		if(i!=len-1)
			cout<<" ";
	}
	cout<<endl;
	return 0;
}
int main()
{
	int next[MAX_LEN],nextval[MAX_LEN];
	char p[MAX_LEN];
	while(cin>>p)
	{
		memset(next,0,sizeof(next));
		memset(nextval,0,sizeof(nextval));
		kmpfind(p,next,nextval);
	}
	return 0;
}
