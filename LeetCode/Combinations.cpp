class Solution {
public:
	void dfs(vector<int>&num,vector<int> &cur,vector<vector<int> > &ret,int n,int last,int dep,int k){
		if(dep==k){
			ret.push_back(cur);return;
		}
		for(int i=last+1;i<=n;i++){
			cur.push_back(i);
			dfs(num,cur,ret,n,i,dep+1,k);
			cur.pop_back();
		}
	}
    vector<vector<int> > combine(int n, int k) {
        vector<int> cur;
    	vector<vector<int> > ret;
    	dfs(num,cur,ret,n,0,0,k);
    	return ret;
    }
};
