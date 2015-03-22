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
	bool flag=false;
    bool hasPathSum(TreeNode *root, int sum) 
    {
        flag=false;
        if(root==NULL)
        	return false;
        dfs(root,sum,root->val);
        if(flag)
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
    void dfs(TreeNode *root,int sum,int tot)
    {
    	if(root->left==NULL&&root->right==NULL)
    	{
  		  	if(tot==sum)
    		{
    			flag=true;
    			return ;
    		}    		
    	}
    	if(!flag)
    	{
    		if(root->left!=NULL)
    			dfs(root->left,sum,tot+root->left->val);
    		if(root->right!=NULL)
    			dfs(root->right,sum,tot+root->right->val);
    	}
    }
};
