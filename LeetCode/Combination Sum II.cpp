class Solution {
public:
	void dfs(vector<int> &num,vector<vector<int> >&res,vector<int> &path,int target,int last,int sum){
		if(sum>target) return;
		if(sum==target){res.push_back(path);return;}
		for(int i=last;i<num.size();i++){
			path.push_back(num[i]);
			dfs(num,res,path,target,i+1,sum+num[i]);
			path.pop_back();
			while(i<num.size()&&num[i]==num[i+1]) i++;
		}
	}
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        vector<vector<int> > res;
        vector<int> path;
        dfs(num,res,path,target,0,0);
        return res;
    }
};