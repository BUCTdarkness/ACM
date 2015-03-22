class Solution {
public:
    string countAndSay(int n) {
		string s="1";
		string next;
		if(n==1) return s;
		for(int i=1;i<n;i++){
			int j=0;
			while(j<s.size()){
				int k=j+1;
				while(k<s.size()&&s[k]==s[j]) k++;
				 next+=(k-j+'0');
				 next+=s[j];
				 j=k;
			}
			s=next;
			next="";
		}
		return s;        
    }
};
