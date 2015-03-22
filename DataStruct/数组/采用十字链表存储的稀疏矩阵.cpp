#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct OLNode
{
	int i,j;
	int e;
	struct OLNode *right,*down;
}OLNode,*OLink;
typedef struct
{
	OLink *rhead,*chead;
	int mu,nu,tu;
}CrossList;
int m,n,t;
CrossList mat;
int a[205][205];
void CreateSMatrix_OL()
{
	OLNode *p,*q;
	mat.mu=m;
	mat.nu=n;
	mat.rhead=new OLink[m+1];
	mat.chead=new OLink[n+1];
	for(int i=1;i<=m;i++)
	{
		mat.rhead[i]=NULL;
	}
	for(int i=1;i<=n;i++)
	{
		mat.chead[i]=NULL;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][j])
			{
				mat.tu++;
				p=new OLNode;
				p->i=i;
				p->j=j;
				p->e=a[i][j];
				p->down=NULL;
				p->right=NULL;
				if(mat.rhead[i]==NULL||mat.rhead[i]->j>j)
				{
					p->right=mat.rhead[i];
					mat.rhead[i]=p;
				}
				else
				{
					for(q=mat.rhead[i];(q->right)&&(q->right->j<j);q=q->right);
					p->right=q->right;
					q->right=p;
				}
				if(mat.chead[j]==NULL||mat.chead[j]->i>i)
				{
					p->down=mat.chead[j];
					mat.chead[j]=p;
				}
				else
				{
					for(q=mat.chead[j];(q->down)&&q->down->i<i;q=q->down);
					p->down=q->down;
					q->down=p;
				}
			}
		}
}
void print()
{
	OLNode *p;
	for(int i=1;i<=mat.mu;i++)
	{
		p=mat.rhead[i];
		for(int j=1;j<=mat.nu;j++)
		{
			if(p&&p->j==j)
			{
				cout<<p->e<<" ";
				p=p->right;
			}
			else
				cout<<0<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	while(cin>>m>>n)
	{
		t=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(a[i][j])
					t++;
			}
		CreateSMatrix_OL();
		print();
	}
	return 0;
}
