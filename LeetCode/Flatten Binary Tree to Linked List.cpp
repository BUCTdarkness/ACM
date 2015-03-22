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
    void flatten(TreeNode *root) {
        if(root==NULL) return;
        if(root->left!=NULL){
        	TreeNode *left=root->left;
        	TreeNode *right=root->right;
        	root->left=NULL;
        	root->right=left;
        	TreeNode *rightMost=root->right;
        	while(rightMost->right!=NULL) rightMost=rightMost->right;
        	rightMost->right=right; 
        }
        flatten(root->right);
    }
};
