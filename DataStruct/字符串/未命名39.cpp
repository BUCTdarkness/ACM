/*
题目描述
读入数据string[ ]，然后读入一个短字符串。要求查找string[ ]中和短字符串的所有匹配，输出行号、匹配字符串。匹配时不区分大小写，并且可以有一个用中括号表示的模式匹配。如“aa[123]bb”，就是说aa1bb、aa2bb、aa3bb都算匹配。
输入格式

输入有多组数据。
每组数据第一行输入n(1<=n<=1000)，从第二行开始输入n个字符串（不含空格），接下来输入一个匹配字符串。

输出

输出匹配到的字符串的行号和该字符串（匹配时不区分大小写）。

样例输入
4
aabb
aaaa
abbb
aaab
a[ab]bb
样例输出
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
