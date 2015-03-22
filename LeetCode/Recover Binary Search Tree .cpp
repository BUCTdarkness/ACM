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
    void recoverTree(TreeNode *root)
    {
        TreeNode *s1=NULL,*s2=NULL,*prev=NULL;
        InOrderTraverse(root,s1,s2,prev);
        swap(s1->val,s2->val);
    }
    void InOrderTraverse(TreeNode *root,TreeNode *&s1,TreeNode *&s2,TreeNode *&prev)
    {
        if(root==NULL) return;
        InOrderTraverse(root->left,s1,s2,prev);
        if(prev!=NULL&&prev->val>root->val)
        {
            s2=root;
            if(s1==NULL) s1=prev;
        }
        prev=root;
        InOrderTraverse(root->right,s1,s2,prev);
    }
};