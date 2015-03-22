class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(A==NULL||n<1) return 1;
        int pos=0;
        while(pos<n){
        	if(A[pos]>0&&A[pos]!=pos+1&&A[pos]-1<n&&A[pos]!=A[A[pos]-1])
        		swap(A[pos],A[A[pos]-1]);
        	else pos++;
        }
        for(int i=0;i<n;i++){
        	if(i+1!=A[i]) return i+1;
        }
        return n+1;
    }
};
