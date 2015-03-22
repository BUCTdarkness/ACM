class Solution {
public:
    int search(int A[], int n, int target) 
    {
        return find(A,0,n-1,target);
    }
    int find(int A[],int l,int r ,int target)
    {
    	if(l>r) return -1;
    	int idx=-1;
    	if(A[l]<=A[r])
    	{
    		int beg=l,end=r;
    		while(beg<=end)
    		{
    			int mid=(beg+end)>>1;
    			if(A[mid]==target)
    			{
    				idx=mid;
    				break;
    			}
    			else if(A[mid]>target)
    			{
    				end=mid-1;
    			}
    			else
    			{
    				beg=mid+1;
    			}
    		}
    	}
    	else
    	{
    		int mid=(l+r)>>1;
    		if(A[mid]==target)
    			idx=mid;
    		else
    		{
    			idx=find(A,l,mid-1,target);
    			idx= (idx==-1)?find(A,mid+1,r,target):idx;
    		}
    	}
    	return idx;
    }
};
