class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> path;
        dfs(s,path,ans);
        return ans;
    }
    inline bool IsPalindrome(string s,int beg,int end){
    	while(beg<end){
    		if(s[beg]==s[end]) {beg++;end--}
  			else return false;
    	}
    	return true;
    }
    void dfs(string s,vector<string> &path,vector<vector<string> > &ans){
    	if(s.size()==0) ans.push_back(path);
    	for(int i=0;i<s.size();i++){
    		int beg=0,end=i;
    		if(IsPalindrome(s,0,i)){
    			path.push_back(s.substr(0,i+1));
    			dfs(s.substr(i+1),path,res);
    			path.pop_back();
    		}
    	}
    }
};
