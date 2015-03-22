#include<iostream>
#include<cstring>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *lchild,*rchild;
}Node,*Tree;
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
void CreateBT(Tree &t,int n)
{
	t=NULL;
	for(int i=0;i<n;i++)
	{
		int v;
		cin>>v;
		InsertBT(t,v);
	}
}
void PreOrderTraverse(Tree t)
{
	if(t)
	{
		cout<<t->data<<" ";
		PreOrderTraverse(t->lchild);
		PreOrderTraverse(t->rchild);
	}
}
void InOrderTraverse(Tree t)
{
	if(t)
	{
		InOrderTraverse(t->lchild);
		cout<<t->data<<" ";
		InOrderTraverse(t->rchild);
	}
}
void SucOrderTraverse(Tree t)
{
	if(t)
	{
		SucOrderTraverse(t->lchild);
		SucOrderTraverse(t->rchild);
		cout<<t->data<<" ";
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
	while(cin>>n)
	{
		Tree t;
		CreateBT(t,n);
		PreOrderTraverse(t);
		cout<<endl;
		InOrderTraverse(t);
		cout<<endl;
		SucOrderTraverse(t);
		cout<<endl;
		DeleteTree(t);
	}
	return 0;
}
