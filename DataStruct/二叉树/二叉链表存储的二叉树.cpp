//the hacker begin!!!


#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
typedef struct BiTNOde
{
	char data;
	struct BiTNOde *lchild,*rchild;
}BiTNOde,*BiTree;
char ch[200];
int i=0;
void visit(char c)
{
	cout<<c<<" ";
}
void PreOrderTraverse(BiTree T)
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void InOrderTraverse1(BiTree T)
{
	stack<BiTree> s;
	while(T||!s.empty())
	{
		if(T)
		{
			s.push(T);
			T=T->lchild;
		}
		else
		{
			T=s.top();
			s.pop();
			visit(T->data);
			T=T->rchild;
		}
	}
	cout<<endl;
}
void InOrderTraverse2(BiTree T)
{
	stack<BiTree> s;
	BiTree p;
	s.push(T);
	while(!s.empty())
	{
		while((p=s.top())&&p)
			s.push(p->lchild);
		s.pop();
		if(!s.empty())
		{
			p=s.top();
			s.pop();
			visit(p->data);
			s.push(p->rchild);
		}
	}
	cout<<endl;
}
void CreateBiTree(BiTree &T)//单用指针就必须得返回地址为什么？ 
{
	if(ch[i]==' ')
	{
		T=NULL;
		i++;
	}
	else
		{
	 		T=new BiTNOde;
 			T->data=ch[i];
 			i++;
 			CreateBiTree(T->lchild);
 			CreateBiTree(T->rchild);
		} 
}
int main()
{
	BiTree T;
	T=new BiTNOde;
	gets(ch);
	CreateBiTree(T);
	PreOrderTraverse(T);
	cout<<endl;
	InOrderTraverse1(T);
	InOrderTraverse2(T);
	return 0;
}
