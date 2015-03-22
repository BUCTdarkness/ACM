class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	vector<int> index;
    	map<int,int> mp;
    	map<int,int>::iterator iter;
    	for(int i=0;i<numbers.size();i++)
    	{
    		iter=mp.find(target-numbers[i]);
    		if(iter!=mp.end())
    		{
    			int start=mp.find(target-numbers[i])->second;
    			int end=i+1;
    			index.push_back(start);
    			index.push_back(end);
    			return index;
    		}
    		else
    		{
    			map<int,int >::iterator it=mp.find(numbers[i]);
    			if(it==mp.end())
    			{
    				mp[numbers[i]]=i+1;
    			}
    		}
    	}
    }
};