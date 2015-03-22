class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex<=0) return vector<int> ();
        vector<int> level;
        level.clear();
        for(int i=0;i<rowIndex;i++)
        {
        	int len=level.size();
        	for(int j=len-1;j>=0;j--)
        	{
        		level[j]+=level[j-1];
        	}
        	level.push_back(1);
        }
        return level;
    }
};
