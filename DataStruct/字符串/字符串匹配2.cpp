/*
��a???����?
?����?��y?Ystring[ ]��?��?o��?����?��????����?��?��??�ꨰa?��2��?��string[ ]?Do��?����?��?��?��??����D?��??��?��?3?DDo??��?��??��?��?��??��?��??����2???��?�䨮D?D���?2��?��?����?��D��???��??D����o?������?��??�꨺??��???�ꨨ??��aa[123]bb?����??����??��aa1bb?��aa2bb?��aa3bb?????��???��
��?��???��?

��?��?��D?��������y?Y?��
??������y?Y�̨���?DD��?��?n(1<=n<=1000)��?�䨮�̨�?tDD?a��?��?��?n??��?��?��?�ꡧ2?o?????��?��??��??���䨺?��?��????��??��?��?��??��

��?3?

��?3??��??��?��?��?��?��?��?DDo?o��??��?��?��?�ꡧ?��??����2???��?�䨮D?D���??��

?����y��?��?
4
aabb
aaaa
abbb
aaab
a[ab]bb
?����y��?3?
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
/*

	cout<<"1"<<t<<endl;
	cout<<"2"<<p<<endl;
	getch();*/
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
void change(char *ch)
{
	int len=strlen(ch);
	for(int i=0;i<len;i++)
	{
		if(ch[i]>='a'&&ch[i]<='z')
			ch[i]+='A'-'a';
	}
}
int main()
{
	int next[MAX_LEN],nextval[MAX_LEN],num,pos;
	char p1[1005][MAX_LEN],p2[1005][MAX_LEN],t[MAX_LEN],t1[MAX_LEN][MAX_LEN];
	bool vis[1005];
	int n;
	while(cin>>n)
	{
		memset(p1,'\0',sizeof(p1));
		memset(p2,'\0',sizeof(p2));
		memset(t,'\0',sizeof(t));
		memset(t1,'\0',sizeof(t1));
		memset(vis,false,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			cin>>p1[i];
			strcpy(p2[i],p1[i]);
		}
		cin>>t;
		num=0;
		pos=0;
		for(int i=0;i<strlen(t);i++)
		{
			if(t[i]=='[')
			{
				pos=i;
				int j=i+1;
				while(t[j]!=']')
				{
					j++;
					num++;
				}
				break;
			}
		}
		change(t);
		int p=pos+1;
		for(int count=0;count<num;count++)
		{
			int i;
			for(i=0;i<pos;i++)
			{
				t1[count][i]=t[i];
			}
			t1[count][i]=t[p];
			p++;
			int q=i+1;
			for(i=pos+num+2;i<strlen(t);i++)
			{
				t1[count][q++]=t[i];
			}
			t1[count][q]='\0';
		}
		if(num==0)
		{
			num=1;
			int j=0;
			for(int i=0;i<strlen(t);i++)
			{
				if(t[i]=='['||t[i]==']')
					continue;
				t1[0][j++]=t[i];
			}
			t1[0][j]='\0';
		}
/*
		cout<<t<<endl;
		for(int i=0;i<num;i++)
			cout<<t1[i]<<endl;
		getch();*/
		for(int i=0;i<n;i++)
			change(p2[i]);
		for(int count=0;count<num;count++)
		{
			for(int i=0;i<n;i++)
			{
				if(!vis[i])
				{
					memset(next,0,sizeof(next));
					memset(nextval,0,sizeof(nextval));
					if(kmpfind(t1[count],p2[i],next,nextval))
						vis[i]=true;
				}
/*
				cout<<pos<<endl;
				cout<<num<<endl;
				cout<<"ssss"<<endl;
				getch();*/
			}
		}
		for(int i=0;i<n;i++)
		{
			if(vis[i]==true)
			{
				cout<<i+1<<" "<<p1[i]<<endl;
			}
		}
	}
	return 0;
}
