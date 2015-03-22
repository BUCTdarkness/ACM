class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size(),len2=s2.size(),len3=s3.size();
        if(len1+len2!=len3) return false;
        bool dp[len3+1][len1+1][len2+1];
        memset(dp,false,sizeof(bool)*(len1+1)*(len2+1)*(len3+1));
        dp[0][0][0]=true;
        for(int k=1;k<=len3;k++){
        	for(int i=0;i<=k&&i<=len1;i++){
 				int j=k-i;
 				if(j>len2) continue;
 				if(i>0&&dp[k-1][i-1][j]&&s3[k-1]==s1[i-1]) dp[k][i][j]=true;
 				if(j>0&&dp[k-1][i][j-1]&&s3[k-1]==s2[j-1]) dp[k][i][j]=true;
        	}
        }
        return dp[len3][len1][len2];
    }
};
