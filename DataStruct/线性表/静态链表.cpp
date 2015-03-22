#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 11
typedef char ElemType[8];
typedef struct
{
	ElemType data;
	int cur;
}NodeType;
NodeType space[MAXSIZE];
typedef struct
{
	int elem;
	int length;
	int listSize;
}SLinkList;
SLinkList S;
void InitSpace_SL()
{
	memset(space,0,sizeof(space));
	for(int i=0;i<MAXSIZE-1;++i)
	{
		space[i].cur=i+1;
	}
	space[MAXSIZE-1].cur=0;
}
int LocateElem(SLinkList &S,ElemType e)
{
	int i;
	i=S.elem;
	while(i&&strcmp(space[i].data,e))
		i=space[i].cur;
	return i;
}
int Malloc()
{
	int i=space[0].cur;
	if(space[0].cur)
		space[0].cur=space[space[0].cur].cur;
	return i;
}
void Free(int k)
{
	space[k].cur=space[0].cur;
	space[0].cur=k;
}
void show()
{
	for(int i=0;i<11;i++)
	{
		cout<<space[i].data<<space[i].cur<<endl;
	}
	cout<<"********************"<<endl;
}
void Insert(int a,ElemType e)
{
	int i=Malloc();
	strcpy(space[i].data,e);
	int j=0;
	while(j<a-1)
	{
		s
	}
}
int main()
{
	char ord[10];
	InitSpace_SL();i8
	while(cin>>ord)
	{
		if(strcmp(ord,"show")==0)
		{
			show();
		}
		if(strcmp(ord,"insert")==0)
		{
			int a;
			ElemType e;
			cin>>a>>e;
			Insert(a,e);
		}
		
	}
	return 0;
}