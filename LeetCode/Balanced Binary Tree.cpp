/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool balance;
	int getHeight(TreeNode *root)
	{
		if(!balance) return -1;
		if(root==NULL) return 0;
		int lc=getHeight(root->left);
		int rc=getHeight(root->right);
		if(abs(lc-rc)>1)
		{
			balance=false;
			return -1;
		}
		return lc>rc?lc+1:rc+1;
	}
    bool isBalanced(TreeNode *root) {
        balance=true;
        getHeight(root);
        if(balance)
        {
        	return true;
        }
        else
        {
        	return false;
        }

    }
};