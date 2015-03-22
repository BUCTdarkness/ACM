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
    vector<TreeNode *> generateTrees(int n) 
    {
        return generate(0,n-1);
    }
    vector<TreeNode *> generate(int beg,int end)
    {
    	vector<TreeNode *> ret;
    	if(beg>end)
    	{
    		ret.push_back(NULL);
    		return ret;
    	}
    	for(int i=beg;i<=end;i++)
    	{
    		vector<TreeNode*> left=generate(beg,i-1);
    		vector<TreeNode*> right=generate(i+1,end);
    		for(int j=0;j<left.size();j++)
    		{
    			for(int k=0;k<right.size();k++)
    			{
    				TreeNode *node=new TreeNode(i+1);
    				node->left=left[j];
    				node->right=right[k];
    				ret.push_back(node);
    			}
    		}
    	}
    	return ret;
    }
};
