#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=40005;
int a[maxn],c[maxn];
int t,n;

int bsearch(int size,int val){
	int low=1,high=size;
	while(low<=high){
		int mid=(low+high)>>1;
		if(val>c[mid]&&val<=c[mid+1])return mid+1;
		else if(val<c[mid])high=mid-1;
		else low=mid+1;
	}
}

int getLIS(){
	int i,j;
	int size=1;
	c[1]=a[1];
	for(i=2;i<=n;i++){
		if(a[i]<=c[1])j=1;
		else if(a[i]>c[size])j=++size;
		else j=bsearch(size,a[i]);
		c[j]=a[i];
	}
	return size;
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		int ans=getLIS();
		printf("%d\n",ans);
	}
	return 0;
}
