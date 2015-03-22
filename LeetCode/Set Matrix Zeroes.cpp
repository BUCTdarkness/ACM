class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool row[matrix.size()];
        bool col[matrix[0].size()];
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        for(int i=0;i<matrix.size();i++)
        	for(int j=0;j<matrix[0].size();j++)
        	{
        		if(matrix[i][j]==0)
        		{
        			row[i]=true;
        			col[j]=true;
        		}
        	}

        for(int i=0;i<matrix.size();i++)
        	for(int j=0;j<matrix[0].size();j++)
        	{
        		if(row[i]==true||col[j]==true)
        		{
        			matrix[i][j]=0;
        		}
        	}
    }
};