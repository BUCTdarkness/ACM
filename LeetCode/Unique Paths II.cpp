class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int f[m][n];
        memset(f,0,sizeof(f));
        f[0][0]=obstacleGrid[0][0]==1?0:1;
        for(int i=1;i<m;i++) f[i][0]=obstacleGrid[i][0]==1?0:f[i-1][0];
        for(int i=1;i<n;i++) f[0][i]=obstacleGrid[0][i]==1?0:f[0][i-1];
        for(int i=1;i<m;i++)
        	for(int j=1;j<n;j++)
        		f[i][j]=obstacleGrid[i][j]==1?0: f[i-1][j]+f[i][j-1];
        return f[m-1][n-1];
    }
};