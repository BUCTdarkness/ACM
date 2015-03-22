/*
��Ŀ����
��������string[ ]��Ȼ�����һ�����ַ�����Ҫ�����string[ ]�кͶ��ַ���������ƥ�䣬����кš�ƥ���ַ�����ƥ��ʱ�����ִ�Сд�����ҿ�����һ���������ű�ʾ��ģʽƥ�䡣�硰aa[123]bb��������˵aa1bb��aa2bb��aa3bb����ƥ�䡣
�����ʽ

�����ж������ݡ�
ÿ�����ݵ�һ������n(1<=n<=1000)���ӵڶ��п�ʼ����n���ַ����������ո񣩣�����������һ��ƥ���ַ�����

���

���ƥ�䵽���ַ������кź͸��ַ�����ƥ��ʱ�����ִ�Сд����

��������
4
aabb
aaaa
abbb
aaab
a[ab]bb
�������
1 aabb
3 abbb*/
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
	
	return 0;
}
