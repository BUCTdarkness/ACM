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
    vector<vector<int> > levelOrder(TreeNode *root) 
	{
        vector<int> ans;
		queue<TreeNode *> q;
		q.push(root);
		while(!q.empty())
		{
			TreeNode *tmp;
			tmp=q.front();
			q.pop();
			ans.push_back(tmp->val);
			q.push(tmp->left);
			q.push(tmp->right);
		}
		return ans;
    }
};
