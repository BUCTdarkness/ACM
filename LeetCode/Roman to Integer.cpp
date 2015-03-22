class Solution{
public:
	int romanToInt(string s){
		int len=s.size();
		if(len<1) return 0;
		map<char,int> m;
		m['I']=1,m['V']=5,m['X']=10,m['L']=50,m['C']=100,m['D']=500,m['M']=1000;
		int i=len-1;
		int sum=m[s[i--]];
		while(i>=0){
			if(m[s[i+1]]>m[s[i]]) sum-=m[s[i--]];
			else sum+=m[s[i--]];
		}
		return sum;
	}
};

