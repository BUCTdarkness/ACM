class Solution {
public:
    int maxSubArray(int A[], int n) {
        int ma=INT_MIN;
        int sum=INT_MIN;
        for(int i=0;i<n;i++)
        {
        	sum=sum<0?A[i]:A[i]+sum;
        	ma=max(ma,sum);
        }
        return ma;
    }
};
