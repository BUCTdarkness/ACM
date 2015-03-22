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
private:
	vector<vector<int>> ans;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        ans.clear();
        vector<int> a;
        dfs(root,sum,0,a);
        return ret;
    }
    void dfs(TreeNode *node,int sum,int curSum,vector<int> a)
    {
    	if(node==NULL)
    	{
    		return;
    	}
    	if(node->left==NULL&&node->right==NULL)
    	{
    		if(curSum+node->val==sum)
    		{
    			a.push_back(node->val);
    			ans.push_back(a);
    		}
    		return;
    	}
    	a.push_back(node->val);
    	dfs(node->left,sum,curSum+node->val,a);
    	dfs(node->right,sum,curSum+node->val,a);
    }
};
