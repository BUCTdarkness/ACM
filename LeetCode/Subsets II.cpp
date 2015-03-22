class Solution {
public:
	void dfs(vector<vector<int> >&ans,vector<int> &S,vector<int> &cur,int last){
		ans.push_back(cur);
		for(int i=last;i<S.size();i++){
			if(i!=last&&S[i]==S[i-1]) continue;
			cur.push_back(S[i]);
			dfs(ans,S,cur,i+1);
			cur.pop_back();
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
		vector<vector<int> > ans;
		if(S.size()==0) return ans;
		vector<int> cur;
		sort(S.begin(),S.end());
		dfs(ans,S,cur,0);
		return ans;        
    }
};
