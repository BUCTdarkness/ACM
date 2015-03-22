class Solution 
{
public:
    int maxProfit(vector<int> &prices)
    {
    	int sum=0;
    	int len=prices.size();
    	for(int i=0;i<len-1;i++)
    	{
    		if(prices[i+1]-prices[i]>0)
    		{
    			sum+=prices[i+1]-prices[i];
    		}
    	}
    	return sum;    
    }
};