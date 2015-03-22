class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,0,0,"",ans);
        return ans;
    }
private:
	void solve(int n,int pos,int neg,string tmp,vector<string>&ans){
		if(pos<neg) return;
		if(pos+neg==2*n){
			if(pos==neg) ans.push_back(tmp);
			return;
		}
		solve(n,pos+1,neg,tmp+'(',ans);
		solve(n,pos,neg+1,tmp+')',ans);
	}
};