class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        if(n<=0) return vector<vector<int> > ();
        vector<int> level;
        vector<vector<int> > ret;
        for(int i=0;i<numRows;i++)
        {
        	int len=level.size();
        	for(int j=len-1;j>=0;j--)
        	{
        		level[j]+=level[j-1];
        	}
        	level.push_back(1);
        	ret.push_back(level);
        }
        return ret;
    }
};
