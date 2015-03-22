#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
struct Node
{
	int data;
	Node *lchild,*rchild;
};
class Tree
{
	private:
		Node *root;
	public:
		Tree()
		{
			root=NULL;
		}
		~Tree()
		{
			DeleteTree();
		}
		void DeleteTree()
		{
			DeleteTree(root);
		}
		void DeleteTree(Node *&node)
		{
			if(node)
			{
				delete(node->lchild);
				delete(node->rchild);
				delete node;
			}
		}
		void InsertBT(int v)
		{
			InsertBT(root,v);
		}
		void InsertBT(Node *&node,int v)
		{
			if(node==NULL)
			{
				node=new Node;
				node->lchild=NULL;
				node->rchild=NULL;
				node->data=v;
				return ; 
			}
			if(v<node->data)
			{
				InsertBT(node->lchild,v);
			}
			else if(v>node->data)
			{
				InsertBT(node->rchild,v);
			}
		}
		void CreateBT(int n)
		{
			root=NULL;
			for(int i=0;i<n;i++)
			{
				int v;
				cin>>v;
				InsertBT(v);
			}
		}
		void SearchBST(int v)
		{
			if(SearchBST(root,v))
			{
				cout<<1<<" ";
			}
			else
			{
				cout<<0<<" ";
			}
		}
		bool SearchBST(Node *&node,int v)
		{
			if(!node)
				return false;
			if(v==node->data)
				return true;
			if(v<node->data)
			{
				return SearchBST(node->lchild,v);
			}
			if(v>node->data)
			{
				return SearchBST(node->rchild,v);	
			}
		}
};
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		Tree t;
		t.CreateBT(n);
		while(k--)
		{
			int v;
			cin>>v;
			t.SearchBST(v);
		}
		cout<<endl;
	}
	return 0;
}
