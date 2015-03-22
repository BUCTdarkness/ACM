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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        if(inorder.size()==0)
        	return NULL;
        TreeNode *head=CreateTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    	return head;
    }
    TreeNode *CreateTree(vector<int> &inorder,int inb,int ine,vector<int> &postorder,int postb,int poste)
    {
    	TreeNode *root=NULL;
    	if(inb>ine)
    	{
    		return NULL;
    	}
    	else
    	{
    		root=new TreeNode(postorder[poste]);
    		int i;
    		for(i=inb;i<=ine&&postorder[poste]!=inorder[i];i++);
    		int len=i-lenb;
    		root->left=CreateTree(inorder,inb,i-1,postorder,postb,postb+len-1);
    		root->right=CreateTree(inorder,i+1,ine,postorder,postb+len,poste-1);
    	}
    	return root;
    }
};

