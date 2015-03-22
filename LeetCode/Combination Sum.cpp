class Solution {
public:
	void dfs(vector<int> &candidates,vector<vector<int> >&res,vector<int> &path,int target,int last,int sum ){
		if(sum>target) return;
		if(sum==target){res.push_back(path);return;}
		for(int i=last;i<candidates.size();i++){
			path.push_back(candidates[i]);
			dfs(candidates,res,path,target,i,sum+candidates[i]);
			path.pop_back();
		}
	}
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs(candidates,res,path,target,0,0);
        return res;
    }
};
