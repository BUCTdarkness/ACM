class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
        	if(s[i]==')'||s[i]==']'||s[i]=='}'){
        		if(st.empty()) return false;
        		else{
        			char c=st.top();
        			st.pop();
        			if( (c=='('&&s[i]!=')') || (c=='['&& s[i]!=']') || (c=='{' &&s[i]!='}'))
        				return false;
        		}
        	}
        	else{
        		st.push(s[i]);
        	}
        }
        return st.empty();
    }
};
