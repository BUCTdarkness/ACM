int beg=-1,end=-1;
void find(int A[],int l,int r,int target){
	if(l>r) return;
	int mid=(l+r)>>1;
	if(A[mid]==target){
		if(mid<beg||beg==-1) beg=mid;
		if(mid>end) end=mid;
		find(A,l,mid-1,target);
		find(A,mid+1,r,target);
	}
	else if(A[mid]<target){
		find(A,mid+1,r,target);
	}
	else{
		find(A,l,mid-1,target);
	}
}
