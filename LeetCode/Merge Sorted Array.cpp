class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int aindex=m-1,bindex=n-1,index=n+m-1;
        while(aindex>=0&&bindex>=0){
        	if(B[bindex]>A[aindex]) A[index--]=B[bindex--];
        	else A[index--]=A[aindex--];
        }
        while(aindex>=0) A[index--]=A[aindex--];
        while(bindex>=0) A[index--]=B[bindex--];
    }
};
