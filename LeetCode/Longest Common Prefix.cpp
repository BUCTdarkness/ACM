class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0) return "";
        string prefix=strs[0];
        for(int i=1;i<strs.size();i++){
        	if(prefix.size()==0||strs[i].size()==0) return "";
        	int len=min(prefix.size(),strs[i].size());
        	int j;
        	for(j=0;j<len;j++){
        		if(prefix[j]!=strs[i][j]) break;
        	}
        	prefix=prefix.substr(0,j);
        }
        return prefix;
    }
};
