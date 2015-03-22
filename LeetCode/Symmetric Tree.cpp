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
    bool check(TreeNode *lnode,TreeNode *rnode){
    	if(lnode==NULL&&rnode==NULL) return true;
    	if(lnode==NULL||rnode==NULL) return false;
    	return lnode->val==rnode->val&&check(lnode->left,rnode->right)&&check(lnode->right,rnode->left);
    }
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return check(root->left,root->right);
    }
};
