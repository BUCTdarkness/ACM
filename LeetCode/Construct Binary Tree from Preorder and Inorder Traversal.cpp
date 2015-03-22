/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if(preorder.size()==0)
        	return NULL;
        TreeNode *head=CreateTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return head;
    }
    TreeNode *CreateTree(vector<int> &preorder,int preb,int pree,vector<int>&inorder,int inb,int ine)
    {
    	TreeNode *root=NULL;
    	if(preb>pree)
    		return NULL;
    	else
    	{
    		root=new TreeNode(preorder[preb]);
    		int i;
    		for(i=inb;i<=ine&&preorder[preb]!=inorder[i];i++);
    		root->left=CreateTree(preorder,preb+1,preb+i-inb,inorder,inb,i-1);
    		root->right=CreateTree(preorder,preb+i-inb+1,pree,inorder,i+1,ine);
    	}
    	return root;
    }
};
