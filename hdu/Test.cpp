#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <windows.h>
using namespace std;
typedef long long ll;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=100000;
const int delta=0.5;           

int searchMax(int a[],int b,int e){
	if(e-b<=1){
		return max(a[b],a[e]);
	}
	int u,v;
	u=searchMax(a,b,b+(e-b)/2);
	v=searchMax(a,b+(e-b)/2+1,e);
	return max(u,v);
}
int searchMin(int a[],int b,int e){
	if(e-b<=1){
		return min(a[b],a[e]);
	}
	int u,v;
	u=searchMin(a,b,b+(e-b)/2);
	v=searchMin(a,b+(e-b)/2+1,e);
	return min(u,v);
}

int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}

ll gcd(ll x,ll y){
	if(x<y)  return gcd(y,x);
	if(y==0) return y;
	else return gcd(x-y,y); 
}//改善取模过程，但迭代次数会增加。

//快速gcd
ll gcd(ll x,ll y){
	if(x<y) return gcd(y,x);
	if(y==0) return x;
	else{
		if(x%2==0){
			if(y%2==0) return gcd(x>>1,y>>1)<<1;
			else return gcd(x>>1,y);
		}
		else{
			if(y%2==0) return gcd(x,y>>1);
			else gcd(y,x-y);
		}
	}
}

//算一个数二进制数中1的个数

int Count(int v){
	int num=0;
	while(v){
		num+=v&0x01;
		v>>=1;
	}
	return num;
}//O(log2v)复杂度与二进制串长度有关

int Count(int v){
	int num=0;
	while(v){
		v&=(v-1);
		num++;
	}
	return num;
}//O（M）复杂度与二进制串中1的个数有关

//算n！后面0的数量
int Count(int v){
	int num=0;
	while(v){
		num+=v/5;
		v/=5;
	}
	return num;
}

//算N！的二进制位中表示最低位1的位置
int lowestOne(int N){
	int ret=0;
	while(N){
		N>>=1;
		ret+=N;
	}
	return ret+1;
}


//寻找发帖的水王。其实也就是找大于n/2的ID，
//这玩意正常O（nlogn+n）可解，但书中给出了O(n)的方法。
int find(int *a,int n){
	int candidate=0,cnt=0;
	for(int i=0;i<n;i++){
		if(cnt==0){
			candidate=a[i];cnt++;
		}
		else{
			if(candidate==a[i]) cnt++;
			else cnt--;
		}
	}
	return candidate;
}

//循环移位O(n) 算法
void reverse(int *arr,int b,int e){
	for(;b<e;b++,e--){
		int tmp=arr[e];
		arr[e]=arr[b];
		arr[b]=tmp;
	}
}
void RightShift(int *arr,int n,int k){
	k%=n;
	reverse(arr,0,n-k-1);
	reverse(arr,n-k,n-1);
	reverse(arr,0,n-1);
}

//数组分割
void solve(){
	bool ok[MAX][MAX]={0};
	ok[0][0]=true;
	for(int k=1;k<=2*n;k++){
		for(int i=min(k,n);i>=1;i--){
			for(int v=0;v<=sum/2;v++){
				if(v>=arr[k]&&ok[i-1][v-arr[k]]){
					ok[i][v]=true;
				}
			}
		}
	}
}

//1的数目 复杂度O(logN)
ll Sumls(ll n){
	ll cnt=0,h=1,lower=0,cur=0,higher=0;
	while(n/h!=0){
		lower=n-(n/h)*h;
		cur=(n/h)%10;
		higher=n/(h*10);
		switch(cnr){
			case 0: cnt+=higher*h;break;
			case 1: cnt+=higher*h+lower+1;break;
			default: cnt+=(higher+1)*h;break
		}
		h*=10;
	}
	return cnt;
}

//寻找第K大数 o(n)算法,但存在比较大的局限性
int search(int k,int *cnt){
	int v=0,sum=0;
	for(v=MAXN-1;v>=0;v--){
		sum+=cnt[v];
		if(sum>=k) break;
	}
}

//寻找K大数O（nlogk）算法
inline int f(int *arr,int n,int v){
	cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i]>=v) cnt++;
	}
	return cnt;
}
int search(int *arr,int n,int k,int Vmax,int Vmin){
	int Vmid;
	while(Vmax-Vmin>delta){
		Vmid=Vmin+(Vmax-Vmin)>>1;
		if(f(arr,n,Vmid)>=k) Vmin=Vmid;
		else Vmax=Vmid;
	}
	return Vmid;
}

//利用堆维护k大数算法 o(n*log(k))
void search(int *h,int k,int x){
	int p,q;
	if(x>h[0]){
		h[0]=x;
		p=0;
		while(p<k){
			q=2*p+1;
			if(q>=k) break;
			if(q<k-1&&(h[q+1]<h[q])) q=q+1;
			if(h[q]<h[p]){
				swap(h[p],h[q]);
				p=q;
			}
			else break;
		}
	}
}             


//利用二分查找两个数字，使得两个数之和等于一个给定的值
strcut Node{
	int x,y;
};
Node search(int *arr,int sum){
	Node t;t.x=-1;t.y=-1;
	for(int i=0,j=n-1;i<j){
		t.x=i;t.y=j;
		if(arr[i]+arr[j]==sum) return t;
		else if(arr[i]+arr[j]<sum) i++;
		else j--;
	}
	return t;
}

//子数组最大乘积
ll search(int *arr,int n,ll *s,ll *t,ll *p){
	s[0]=1;t[n]=1;t[n+1]=1;
	ll ret=INT_MIN;
	for(int i=1;i<=n;i++) s[i]=s[i-1]*arr[i];
	for(int i=n;i>=1;i--) t[i]=t[i+1]*arr[i];
	for(int i=1;i<=n;i++) {
		p[i]=s[i-1]*t[i+1];
		ret=max(ret,p[i]);
	}
	return ret;
}

//子数组之和最大值
int MaxSum(int *A,int n){
	int nStart=A[n-1],nAll=A[n-1];
	for(int i=n-2;i>=0;i--){
		if(nStart<0) nStart=0;
		nStart=A[i];
		if(nStart>nAll) nAll=nStart;
	}
	return nAll;
}

//子矩阵和最大值
inline int BC(int *A,int a,int c,int m){
	int sum=0;
	for(int i=a;i<=c;i++) sum+=A[i][m];
	return sum;
}
int MaxSum(int *A,int n,int m){
	int ret=INT_MIN,start=0,all=0;
	for(int a=1;a<=n;a++){
		for(int c=1;c<=m;c++){
			start=BC(A,a,c,m);all=BC(A,a,c,m);
			for(int i=m-1;i>=1;i--){
				if(start<0) start=0;
				start+=BC(A,a,c,i);
				if(start>all) all=start;
			}
			ret=max(ret,all);
		}
	}
	return ret;
}


void RecursiveSearch(int *num,int *ans,int index,int n){
	if(index==n){
		for(int i=0;i<m;i++) printf("%c",c[num[i]][ans[i]]);
		printf("\n");
		return;
	}
	for(ans[index]=0;ans[index]<tot[num[index]];ans[index]++){
		RecursiveSearch(num,ans,index+1,n);
	}
}


int main(){

	return 0;
}
