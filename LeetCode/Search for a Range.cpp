class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
    	assert(A!=NULL&&n!=0);
    	vector<int> res;
    	int beg=0,end=n-1;
    	while(beg<=end){
    		int mid=(beg+end)/2;
    		if(A[mid]==target){
    			while(mid>=0&&A[mid]==target) mid--;
    			res.push_back(++mid);
    			while(mid<=n-1&&A[mid]==target) mid++;
    			res.push_back(--mid);
    			return res;
    		}
    		else if(A[mid]<target) beg=mid+1;
    		else end=mid-1;
    	}
    	res.push_back(-1);res.push_back(-1);
    	return res;
    }
};
