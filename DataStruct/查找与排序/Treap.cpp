//AVL写起来有点麻烦，先写个Treap再说,虽然这个一样麻烦。。。
//Treap ,avl, B-树，红黑树 
#include<iostream> 
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
struct Node
{
	Node *ch[2];
	int r;
	int v;
	bool operator<(const Node &rhs) const
	{
		return r<rhs.r;
	}
	int cmp(int x) const 
	{
		if(x==v) return -1;
		return x<v?0:1;//0代表左旋，1代表右旋 
	}
};
class Treap
{
	private:
		Node *o;
	public:
		Treap()
		{
			o=NULL;
		}
		void rotate(Node *&o,int d)
		{
			Node *k=o->ch[d^1];
			o->ch[d^1]=k->ch[d];
			k->ch[d]=o;
			o=k;
		}
		void insertBT(int x)
		{
			insertBT(o,x);
		}
		void insertBT(Node *&node,int x)
		{
			if(node==NULL)
			{
				node=new Node;
				node->ch[0]=NULL;
				node->ch[1]=NULL;
				node->v=x;
				node->r=rand()%1000;
			}
			else
			{
				int d=node->cmp(x);
				insertBT(node->ch[d],x);
				if(node->ch[d]>o)
					rotate(node,d^1);
			}
		}
		void CreateBT(int n)
		{
			o=NULL;
			for(int i=0;i<n;i++)
			{
				int v;
				cin>>v;
				insertBT(v);
			}
		}
		void find(int x)
		{
			cout<<find(o,x)<<" ";
		}
		int find(Node *node,int x)
		{
			while(node!=NULL)
			{
				int d=node->cmp(x);
				if(d==-1)
					return 1;
				else
				{
					node=node->ch[d];
				}
			}
			return 0;
		}
};
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		Treap t;
		t.CreateBT(n);
		while(k--)
		{
			int v;
			cin>>v;
			t.find(v);
		}
		cout<<endl;
	}
	return 0;
}
