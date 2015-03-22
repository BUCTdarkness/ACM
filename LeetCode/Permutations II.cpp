class Solution {
public:
	void dfs(vector<int> &num,vector<bool> &visit,int dep,vector<vector<int> >&ret,vector<int> &cur){
		if(dep==num.size()){
			ret.push_back(cur);
			return;
		}
		else{
			for(int i=0;i<num.size();i++){
				if(visit[i]==false){
					if(i!=0&&num[i]==num[i-1]&&visit[i-1]==false) continue;
					cur.push_back(num[i]);
					visit[i]=true;
					dfs(num,visit,dep+1,ret,cur);
					visit[i]=false;
					cur.pop_back();
				}
			}
		}
	}
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        vector<bool> visit;
        for(int i=0;i<num.size();i++) visit.push_back(false);
        vector<int> cur;
    	vector<vector<int> > ret;
    	dfs(num,visit,0,ret,cur);
    	return ret;
    }
};