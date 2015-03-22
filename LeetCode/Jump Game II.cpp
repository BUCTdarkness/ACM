class Solution {
public:
    int jump(int A[], int n) {
        int f[n];
        int ma=0;
        fill(f,f+n,0);
        for(int i=0;i<n;i++){
        	int j;
        	for(j=ma+1-i;i+j<n&&j<=A[i];j++){
        		f[i+j]=f[i]+1;
        	}
        	ma=max(ma,i+j-1);
        }
        return f[n-1];
    }
};
