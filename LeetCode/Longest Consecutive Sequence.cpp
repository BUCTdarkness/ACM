class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size()==0) return 0;
        unordered_set<int> st;
        unordered_set<int> vt;
        st.clear();vt.clear();
        for(int i=0;i<num.size();i++) st.insert(num[i]);
        int ans=0;
    	for(int i=0;i<num.size();i++){
    		if(vt.find(num[i])!=vt.end()) continue;    			
    		int tmp=1,left=num[i]+1,right=num[i]-1;
    		while(st.find(left)!=st.end()){
    			vt.insert(left--);
    			tmp++;
    		}
    		while(st.find(right)!=st.end()){
    			vt.insert(right++);
    			tmp++;
    		}
    		ans=max(tmp,ans);
    	}
    	return ans;
    }
};
