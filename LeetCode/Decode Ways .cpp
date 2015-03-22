class Solution {
public:
    int numDecodings(string s) {
  		int len=s.size();
  		if(len==0) return 0;
  		int dp[len];
  		fill(dp,dp+len,0);
  		for(int i=0;i<len;i++){
  			if(s[i]<'0'||s[i]>'9') return 0;
  			if(s[i]=='0'){
  				if(i==0||s[i-1]=='0'||s[i-1]>='3') return 0;
  				dp[i]=i>1?dp[i-2]:1;
  			}
  			else{
  				if(i>0&&(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')){
  					dp[i]=(i>0?dp[i-1]:1)+(i>1?dp[i-2]:1);
  				}
  				else{
  					dp[i]=i>0?dp[i-1]:1;
  				}
  			}
  		}
  		return dp[len-1];      
    }
};