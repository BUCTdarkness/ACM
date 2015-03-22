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
	bool check(TreeNode *node,int lv,int rv){
		if(node==NULL) return true;
		return lv<node->val&&node->val<rv&&check(node->left,lv,node->val)&&check(node->right,node->val,rv);
	}
    bool isValidBST(TreeNode *root) {
    	return check(root,INT_MIN,INT_MAX);    
    }
};