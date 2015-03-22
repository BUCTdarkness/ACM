class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> st;
        int len[s.size()];
        memset(len,0,sizeof(int)*s.size());
        for(int i=0;i<s.size();i++){
        	if(s[i]=='(') st.push(i);
        	else if(s[i]==')'){
        		if(!st.empty()){
        			int j=st.top();
        			len[i]=(i-j+1)+(j>0?len[j-1]:0);
        			ans=max(ans,len[i]);
        			st.pop();
        		}
        	}
        }
        return ans;
    }
};
