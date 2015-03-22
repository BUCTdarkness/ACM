class Solution {
public:
	void dfs(vector<int> &S,vector<vector<int> > &ret,vector<int> cur,int last,int dep){
		ret.push_back(cur);
		if(dep==S.size()) return;
		vector<int> b(cur);
		for(int i=last;i<S.size();i++){
			b.push_back(S[i]);
			dfs(S,ret,b,i+1,dep+1);
            b.pop_back();
		}
	}
    vector<vector<int> > subsets(vector<int> &S) {
    	sort(S.begin(),S.end());
        vector<vector<int> > ret;
        vector<int> cur;
        dfs(S,ret,cur,0,0);
        return ret;
    }
};