class Solution 
{
public:
	int f[1010][1010];
	int getv(int begin,int end)
	{
		if(begin>end)
			return 1;
		return f[begin][end];
	}
    int numTrees(int n) 
    {
    	for(int i=0;i<n;i++)
    	{
    		f[i][i]=1;
    	}
    	for(int len=2;len<=n;len++)
    	{
    		for(int begin=0;begin<n;begin++)
    		{
    			int end=begin+len-1;
    			if(end>=n)
    				break;
    			f[begin][end]=0;
    			for(int mid=begin;mid<=end;mid++)
    			{
    				f[begin][end]+=getv(begin,mid-1)*getv(mid+1,end);
    			}
    		}
    	}
    	return f[0][n-1];
    }
};


