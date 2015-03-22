class Solution {
public:
	//处理逆波兰表达式
    int evalRPN(vector<string> &tokens) {
		if(tokens.size()==1) return stoi(*tokens.begin());
		stack<int> st;
		vector<string>::iterator it=tokens.begin();
		int x=0,y=0;
		while(it!=tokens.end()){
			if(*it=="+"||*it=="-"||*it=="*"||*it=="/"){
				y=st.top();st.pop();
				x=st.top();st.pop();
				if(*it=="+") st.push(x+y);
				else if(*it=="-") st.push(x-y);
				else if(*it=="*") st.push(x*y);
				else if(*it=="/") st.push(x/y);
			}
			else st.push(stoi(*it));
			it++;
		}
		return st.top();        
    }
};
