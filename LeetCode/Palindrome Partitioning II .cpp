class Solution {
public:
    int minCut(string s) {
    	int len=s.size();
        int *dp=new int[len+2];
        for(int i=len;i>=0;i--) dp[i]=len-i;
        bool **p=new bool *[len+2];
        for(int i=0;i<len;i++){
        	p[i]=new bool[len+2];
        	memset(p[i],false,sizeof(bool)*len);
        }
        for(int i=len-1;i>=0;i--)
        	for(int j=i;j<len;j++){
        		if(s[i]==s[j]&&(j-i<2||p[i+1][j-1])){
        			p[i][j]=true;
        			dp[i]=min(dp[i],1+dp[j+1]);
        		}
        	}
        return dp[0]-1;
    }
};
