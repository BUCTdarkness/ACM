#include<iostream>
#include<cstring>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
}Node,*Tree;
int  tot=0;
void InsertBT(Tree &t,int v)
{
	if(t==NULL)
	{
		t=new Node;
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=v;
		return;
	}
	if(v<t->data)
	{
		InsertBT(t->lchild,v);
	}
	else if(v>t->data)
		{
			InsertBT(t->rchild,v);
		}
}
void CreateBT(Tree &t,char *str)
{
	t=NULL;
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		int v;
		v=str[i]-'0';
		InsertBT(t,v);
	}
}
void PreOrderTraverse(Tree t,char *s)
{
	if(t)
	{
		s[tot]= t->data+'0';
		tot++;
		PreOrderTraverse(t->lchild,s);
		PreOrderTraverse(t->rchild,s);
	}
}
void DeleteTree(Tree &t)
{
	if(t)
	{
		delete(t->lchild);
		delete(t->rchild);
		delete(t);
	}
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		char str[15];
		char s[15];
		char scmp[15];
		Tree t;
		cin>>str;
		CreateBT(t,str);
		tot=0;
		PreOrderTraverse(t,s);
		s[tot]='\0';
		DeleteTree(t);
		t=NULL;
		while(n--)
		{
			cin>>str;
			CreateBT(t,str);
			tot=0;
			PreOrderTraverse(t,scmp);
			scmp[tot]='\0';
			DeleteTree(t);
			t=NULL;
			if(strcmp(s,scmp)==0)
			{
				cout<<"YES"<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
