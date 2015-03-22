class Solution {
public:
    int numDistinct(string S, string T) {
    	if(S.size()<T.size()) return 0;
        int dp[S.size()+2][T.size()+2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=S.size();i++)
        	for(int j=1;j<=T.size();j++){
        		if(S[i-1]==T[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        		else dp[i][j]=dp[i-1][j];
        	}
        return dp[S.size()][T.size()];
    }
};