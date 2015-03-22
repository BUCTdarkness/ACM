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
    int sumNumbers(TreeNode *root) {
        int sum=0;
        sumPath(root,0,sum);
        return sum;
    }
    void sumPath(TreeNode *root,int prevSum,int &sum){
        if(root==NULL) return ;
        prevSum=prevSum*10+root->val;
        if(root->left==NULL&&root->right==NULL) sum+=prevSum;
        sumPath(root->left,prevSum,sum);
        sumPath(root->right,prevSum,sum);
    }
};