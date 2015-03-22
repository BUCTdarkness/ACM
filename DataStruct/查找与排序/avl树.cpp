#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define LH 1
#define RH -1
#define EH 0
using namespace std;
struct Node
{
	int data;
	int bf;
	Node *lchild,*rchild;
};
class BstTree
{
	private:
		Node *root;
	public:
		BstTree()
		{
			root=NULL;
		}
		~BstTree()
		{
			DeleteTree();
		}
		void DeleteTree()
		{
			DeleteTree(root);
		}
		void DeleteTree(Node *& node)
		{
			if(node)
			{
				delete(node->lchild);
				delete(node->rchild);
				delete(node);
			}
		}
		void L_Rotate(Node *& p)
		{
			Node *l;
			l=p->rchild;
			p->rchild=l->lchild;
			l->lchild=p;
			p=l;
		}
		void R_Rotate(Node *& p)
		{
			Node *r;
			r=p->lchild;
			p->lchild=r->rchild;
			r->rchild=p;
			p=r;
		}
		void LeftBalance(Node *& t)
		{
			Node *l,*rc;
			l=t->lchild;
			switch(l->bf)
			{
				case LH:
					t->bf=l->bf=EH;
					R_Rotate(t);
					break;
				case RH:
					rc=l->rchild;
					switch(rc->bf)
					{
						case LH:
							t->bf=RH;
							l->bf=EH;
							break;
						case EH:
							t->bf=l->bf=EH;
							break;
						case RH:
							t->bf=EH;
							l->bf=LH;
							break;
					}
					rc->bf=EH;
					L_Rotate(t->lchild);
					R_Rotate(t);
			}
		}
		void RightBalance(Node *& t)
		{
			Node *r,*lc;
			r=t->rchild;
			switch(r->bf)
			{
				case RH:
					t->bf=r->bf=EH;
					L_Rotate(t);
					break;
				case LH:
					lc=r->lchild;
					switch(lc->bf)
					{
						case RH:
							t->bf=LH;
							r->bf=EH;
							break;
						case EH:
							t->bf=r->bf=EH;
							break;
						case LH:
							t->bf=EH;
							r->bf=RH;
							break;
					}
					lc->bf=EH;
					R_Rotate(t->rchild);
					L_Rotate(t);
			}
		}
		void InsertAvl(int v)
		{
			int taller;
			InsertAvl(root,v,taller);
		}
		int InsertAvl(Node *& node,int v,int taller)
		{
			if(!node)
			{
				node=new Node;
				node->data=v;
				node->lchild=node->rchild=NULL;
				node->bf=EH;
				taller=1;
			}
			else
			{
				if(v==node->data)
				{
					taller=0;
					return 0;
				}
				if(v<node->data)
				{
					if(!InsertAvl(node->lchild,v,taller))
					{
						return 0;
					}
					if(taller)
					{
						switch(node->bf)
						{
							case LH:
								LeftBalance(node);
								taller=0;
								break;
							case EH:
								node->bf=LH;
								taller=1;
								break;
							case RH:
								node->bf=EH;
								taller=0;
								break;
						}
					}
				}
				else
				{
					if(!InsertAvl(node->rchild,v,taller))
						return 0;
					if(taller)
					{
						switch(node->bf)
						{
							case LH:
								node->bf=EH;
								taller=0;
								break;
							case EH:
								node->bf=RH;
								taller=1;
								break;
							case RH:
								RightBalance(node);
								taller=0;
								break;
						}
					}
				}
			}
			return 1;
		}
		bool SearchBST(int key)
		{
			return SearchBST(root,key);
		}
		bool SearchBST(Node *&node,int key)
		{
			if(node)
			{
				if(node->data==key)
					return true;
				if(key<node->data)
					return SearchBST(node->lchild,key);
				else
					return SearchBST(node->rchild,key);
			}
			return false;
		}
}; 
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		BstTree t;
		for(int i=0;i<n;i++)
		{
			int v;
			cin>>v;
			t.InsertAvl(v);
		}
		while(k--)
		{
			int v;
			cin>>v;
			if(t.SearchBST(v))
				cout<<1<<" ";
			else
				cout<<0<<" ";
		}
		cout<<endl;
	}
	return 0;
}
