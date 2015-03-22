class Solution {
public:
	const int INF=0x7f3f3f3f;
	int dp[1000];
    int minimumTotal(vector<vector<int> > &triangle) {
        int n=triangle.size();
        memset(dp,INF,sizeof(dp));
        dp[1]=triangle[0][0];
        for(int i=2;i<=n;i++)
        	for(int j=i;j>=1;j--)
        		dp[j]=min(dp[j-1],dp[j])+triangle[i-1][j-1];
        int ans=INF;
        for(int i=1;i<=n+1;i++) ans=min(ans,dp[i]);
        return ans;
    }
};
