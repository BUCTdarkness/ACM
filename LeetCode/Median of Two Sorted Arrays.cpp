//该题主要是涉及到了k小数算法
class Solution {
public:
	double findKth(int *a,int m,int *b,int n,int k){
		if(n<m) return findKth(b,n,a,m,k);
		if(m==0) return b[k-1];
		if(k==1) return min(a[0],b[0]);
		int pa=min(m,k/2),pb=k-pa;
		if(a[pa-1]<b[pb-1]) return findKth(a+pa,m-pa,b,n,k-pa);
		else if(a[pa-1]>b[pb-1]) return findKth(a,m,b+pb,n-pb,k-pb);
		else return a[pa-1];
	}
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int cnt=m+n;
        if(cnt&1) return findKth(a,m,b,n,cnt/2+1); 
        else return (findKth(a,m,b,n,cnt/2)+findKth(a,m,b,n,cnt/2+1))/2;
    }
};
