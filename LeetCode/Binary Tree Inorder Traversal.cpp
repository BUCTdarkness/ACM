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
    vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> ans;
		vector<int> left;
		vector<int> right;
		
		if(root==NULL)
			return ans;
		left=inorderTraversal(root->left);
		if(left.size()!=0)
			ans.insert(ans.end(),left.begin(),left.end());
		ans.push_back(root->val);
		right=inorderTraversal(root->right);
		if(right.size()!=0)
			ans.insert(ans.end(),right.begin(),right.end());
		return ans;
	}
};