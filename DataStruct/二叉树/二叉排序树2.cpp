#include<iostream>
#include<cstring>
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
        else  if(v>node->data)
        {
            InsertBT(node->rchild,v);
        }
    }
    void CreateBT(int n)
    {
        CreateBT(root,n);
    }
    void CreateBT(Node *&node,int n)
    {
        node=NULL;
        for(int i=0;i<n;i++)
        {
            int v;
            cin>>v;
            InsertBT(v);
        }
    }
    void PreOrderTraverse()
    {
        PreOrderTraverse(root);
        cout<<endl;
    }
    void PreOrderTraverse(Node *node)
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
    void InOrderTraverse(Node *node)
    {
        if(node)
        {
            InOrderTraverse(node->lchild);
            cout<<node->data<<" ";
            InOrderTraverse(node->rchild);
        }
    }
    void SucOrderTraverse()
    {
        SucOrderTraverse(root);
        cout<<endl;
    }
    void SucOrderTraverse(Node *node)
    {
        if(node)
        {
            SucOrderTraverse(node->lchild);
            SucOrderTraverse(node->rchild);
            cout<<node->data<<" ";
        }
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
    int getHeight()
    {
        return getHeight(root);
    }
    int getHeight(Node *node)
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
};
int main()
{
    int n;
    while(cin>>n)
    {
        Tree t;
        t.CreateBT(n);
        t.PreOrderTraverse();
        t.InOrderTraverse();
        t.SucOrderTraverse();
    }
    return 0;
}

