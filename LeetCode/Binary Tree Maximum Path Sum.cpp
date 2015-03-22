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
	int MAX=-1<<30;
    int maxPathSum(TreeNode *root)
    {
        if(root==NULL)
            return 0;
        MAX=0;
        MaxPathSum(root);
        return MAX;
    }
    int MaxPathSum(TreeNode *root)
    {
        if(root==NULL)
        	return 0;
        int left,right,value=root->val;
        left=MaxPathSum(root->left);
        right=MaxPathSum(root->right);
        if(left>0)
        	value+=left;
        if(right>0)
        	value+=right;
        MAX=max(MAX,value);
        return max(root->val,max(root->val+left,root->val+right));
    }
};
