class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(matrix.empty()||matrix[0].empty()) return false;
        int x=0,y=n-1;
        while(x>=0&&x<m&&y>=0&&y<n)
        {
        	if(matrix[x][y]==target) return true;
        	else if(matrix[x][y]>target) y--;
        	else x++;
        }
        return false;
    }
};
