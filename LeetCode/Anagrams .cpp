class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string,int> mp;
        vector<string> ans;
        for(int i=0;i<strs.size();i++){
        	string tmp=strs[i];
        	sort(tmp.begin(),tmp.end());
        	if(mp.count(tmp)<=0) mp[tmp]=i;
        	else{
        		if(mp[tmp]==-1){
        			ans.push_back(strs[i]);
        		}
        		else{
        			ans.push_back(strs[mp[tmp]]);
        			mp[tmp]=-1;
        			ans.push_back(strs[i]);
        		}
        	}
        }
        return ans;
    }
};
