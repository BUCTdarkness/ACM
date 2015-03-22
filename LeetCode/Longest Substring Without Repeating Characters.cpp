class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int mlen=0,idx=-1;
		int loc[s.size()];
		memset(loc,-1,sizeof(loc));
		for(int i=0;i<s.size();i++){
			if(loc[s[i]]>idx) idx=loc[s[i]];
			mlen=max(mlen,i-idx);
			loc[s[i]]=i;
		}
		return mlen;
    }
};
