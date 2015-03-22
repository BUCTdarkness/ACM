#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
#define MAXSIZE 11
typedef char ElemType[8];
typedef struct
{
	ElemType data;
	int cur;
}Node,SLinkList[MAXSIZE];
typedef struct 
{
	int elem;
	int length;
}SL;
SL S;
void InitSpace_SL(SLinkList l)
{
	memset(l,0,sizeof(l));
	for(int i=0;i<MAXSIZE-1;++i)
	{
		l[i].cur=i+1;
		l[i].data[0]='\0';
	}
	l[MAXSIZE-1].data[0]='\0';
	l[MAXSIZE-1].cur=0;
	S.elem=1;
	S.length=0;
	l[S.elem].cur=0;
	l[0].cur=2;
}
int LocateElem(SLinkList l,ElemType e)
{
	int i;
	i=S.elem;
	while(i&&strcmp(l[i].data,e))
		i=l[i].cur;
	return i;
}
int Malloc(SLinkList l)
{
	int i=l[0].cur;
	if(l[0].cur)
	{
		l[0].cur=l[l[0].cur].cur;
		S.length++;
	}
	return i;
}
void Free(SLinkList l,int k)
{
	l[k].cur=l[0].cur;
	l[0].cur=k;
	S.length--;
}
void show(SLinkList l)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(l[i].data[0]=='\0')
		{
			for(int j=0;j<8;j++)
				cout<<" ";
			printf("%2d\n",l[i].cur);
		}
		else
		{
			printf("%-8s%2d\n",l[i].data,l[i].cur);
		}
	}
	cout<<"********************"<<endl;
}
void Insert(SLinkList l,int a,ElemType e)
{
	int k=S.elem;
	for(int j=0;j<a-1;++j)
		k=l[k].cur;
	int v=Malloc(l);
	if(v)
	{
		strcpy(l[v].data,e);
		l[v].cur=l[k].cur;
		l[k].cur=v;
	}
}
void DeleteList(SLinkList l,int i)
{
	int k=S.elem;
	for(int j=0;j<i-1;++j)
	{
		k=l[k].cur;
	}
	int a=l[k].cur;
	l[k].cur=l[l[k].cur].cur;
	Free(l,a);
}
int main()
{
	SLinkList l;
	InitSpace_SL(l);
	char ord[10];
	while(cin>>ord)
	{
		if(strcmp(ord,"show")==0)
		{
			show(l);
		}
		if(strcmp(ord,"insert")==0)
		{
			int a;
			ElemType e;
			cin>>a>>e;
			Insert(l,a,e);
		}
		if(strcmp(ord,"delete")==0)
		{
			int a;
			cin>>a;
			DeleteList(l,a);
		}
		if(strcmp(ord,"search")==0)
		{
			ElemType e;
			cin>>e;
			printf("%2d\n",LocateElem(l,e));
			cout<<"********************"<<endl;
		}
	}
	return 0;
}
