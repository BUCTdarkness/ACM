#include<cstring>
using namespace std;
struct BiNode
{
	char data;
	BiNode *lchild;
	BiNode *rchild;
};
class BiTree
{
	private:
		BiNode *root;
	public:
	BiTree()
	{
		root=NULL;
	}
	~BiTree()
	{
		DeleteTree(root);
	}
	void DeleteTree(BiNode *&node)
	{
		if(node)
		{
			DeleteTree(node->lchild);
			DeleteTree(node->rchild);
			delete node;
		}
	}
	int getHeight()
	{
		return getHeight(root);
	}
	int getHeight(BiNode *node)
	{
		if(node==NULL)
		{
			return 0;
		}
		else
		{
			int lh=getHeight(node->lchild);
			int rh=getHeight(node->rchild);
			return lh>rh?lh+1:rh+1;
		}
	}
	void input()
	{
		input(root);
	}
	void input(BiNode *&node)
	{
		char ch;
		if(ch=getchar())
		{
			if(ch==' ')
			{
				node=NULL;
			}
			else
			{
				node=new BiNode;
				node->data=ch;
				input(node->lchild);
				input(node->rchild);
			}
		}
	}
	void PreOrderTraverse()
	{
		PreOrderTraverse(root);
		cout<<endl;
	}
	void PreOrderTraverse(BiNode *node)
	{
		if(node)
		{
			cout<<node->data<<" ";
			PreOrderTraverse(node->lchild);
			PreOrderTraverse(node->rchild);
		}
	}
	void InOrderTraverse()
	{
		InOrderTraverse(root);
		cout<<endl;
	}
	void InOrderTraverse(BiNode *node)
	{
		if(node)
		{
			InOrderTraverse(node->lchild);
			cout<<node->data<<" ";
			InOrderTraverse(node->rchild);
		}
	}
	void PostOrderTraverse()
	{
		PostOrderTraverse(root);
		cout<<endl;
	}
	void PostOrderTraverse(BiNode *node)
	{
		if(node)
		{
			PostOrderTraverse(node->lchild);
			PostOrderTraverse(node->rchild);
			cout<<node->data<<" ";
		}
	}
	int find(const string &str,char c)
	{
		for(int i=0;i<str.size();i++)
		{
			if(c==str[i])
				return i;
		}
		return -1;
	}
	void PreMid(const string &pre,const string &mid)
	{
		PreMid(root,pre,mid);
	}
	void PreMid(BiNode *&node,const string &pre,const string &mid)
	{
		if(pre.size()==0)
		{
			node=NULL;
			return ;
		}
		int k=find(mid,pre[0]);
		node=new BiNode;
		node->data=pre[0];
		PreMid(node->lchild,pre.substr(1,k),mid.substr(0,k));
		PreMid(node->rchild,pre.substr(k+1,pre.size()-k-1),mid.substr(k+1,mid.size()-k-1));
	}
	void PostMid(const string &post,const string &mid)
	{
		PostMid(root,post,mid);
	}
	void PostMid(BiNode *&node,const string &post,const string &mid)
	{
		if(post.size()==0)
		{
			node=NULL;
			return ;
		}
		int k=find(mid,post[post.size()-1]);
		node=new BiNode;
		node->data=post[post.size()-1];
		PostMid(node->lchild,post.substr(0,k),mid.substr(0,k));
		PostMid(node->rchild,post.substr(k,mid.size()-k-1),mid.substr(k+1,mid.size()-k-1));
	}
};
