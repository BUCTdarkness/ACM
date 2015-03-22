class Solution 
{
public:
    int maxProfit(vector<int> &prices) 
    {
    	int len=prices.size();
    	if(len==0)
    		return 0;
    	vector<int> f1(len);
    	vector<int> f2(len);
    	int minv=prices[0];
    	f1[0]=0;
    	for(int i=1;i<len;i++)
    	{
    		minv=min(minv,prices[i]);
    		f1[i]=max(f1[i-1],prices[i]-minv);
    	}
    	int maxv=prices[len-1];
    	f2[len-1]=0;
    	for(int i=len-2;i>=0;i--)
    	{
    		maxv=max(maxv,prices[i]);
    		f2[i]=max(f2[i+1],maxv-prices[i]);
    	}
    	int sum=0;
    	for(int i=0;i<len;i++)
    	{
    		sum=max(sum,f1[i]+f2[i]);
    	}
    	return sum;
    }
};

