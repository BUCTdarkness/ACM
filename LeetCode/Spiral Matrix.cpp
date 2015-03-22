class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.size()==0) return vector<int>();
        int x1=0,y1=0,x2=matrix.size()-1,y2=matrix[0].size()-1;
        vector<int> ans;
        while(x1<=x2&&y1<=y2){
        	for(int i=y1;i<=y2;i++) ans.push_back(matrix[x1][i]);
        	for(int i=x1+1;i<=x2;i++) ans.push_back(matrix[i][y2]);
        	if(x2!=x1)
        		for(int i=y2-1;i>=y1;i--) ans.push_back(matrix[x2][i]);
        	if(y2!=y1)
        		for(int i=x2-1;i>x1;i--) ans.push_back(matrix[i][y1]);
        	x1++,y1++,x2--,y2--;
        }
        return ans;
    }
};
