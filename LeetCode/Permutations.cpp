class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        vector<int> temp;
        bool used[num.size()];
        memset(used,0,sizeof(used));
        dfs(num,0,used,temp,ans);
        return ans;
    }
    void dfs(vector<int>&num,int h,bool *used,vector<int> &temp,vector<vector<int> > &ans){
    	if(h==num.size()){
    		ans.push_back(temp);
    		return;
    	}
    	for(int i=0;i<num.size();i++){
    		if(!used[i]){
    			used[i]=true;
    			temp.push_back(num[i]);
    			dfs(num,h+1,used,temp,ans);
    			temp.pop_back();
    			used[i]=false;
    		}
    	}
    }
};
