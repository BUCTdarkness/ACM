class Solution {
public:
    int trap(int A[], int n) {
  		if(n==0) return 0;
  		int maxindex=0,ma,sum=0;
  		for(int i=1;i<n;i++){
  			if(A[i]>A[maxindex]) maxindex=i;
  		}
  		ma=A[0];
  		for(int i=1;i<maxindex;i++){
  			if(A[i]>ma) ma=A[i];
  			else sum+=ma-A[i];
  		}
  		ma=A[n-1];
  		for(int i=n-2;i>maxindex;i--){
  			if(A[i]>ma) ma=A[i];
  			else sum+=ma-A[i];
  		}
  		return sum;      
    }
};