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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans; ans.clear();
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        int flag=0;
        q.push(root);q.push(NULL);
        vector<int> tmp;
        while(!q.empty()){
        	TreeNode *p=q.front();q.pop();
        	if(p!=NULL){
        		tmp.push(p->val);
        		if(p->left) q.push(p->left);
        		if(p->right) q.push(p->right);
        	}
        	else{
        		if(tmp.size()>0){
        			q.push(NULL);
        			if(flag==1) reverse(tmp.begin(),tmp.end());
        			ans.push_back(tmp);
        			flag=1-flag;
        			tmp.clear();
        		}
        	}
        }
        return ans;
    }
};
