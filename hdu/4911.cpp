#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
#define CLR(A)  memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=500000;
int L[MAX],R[MAX],a[MAX];
void merge(int *a,int p,int mid ,int q,ll &cnt){
    int i,j;
    for(i=p;i<=mid;i++) L[i]=a[i];
    for(j=mid+1;j<=q;j++) R[j]=a[j];
    i=p;j=mid+1;
    int w=p;
    while(i<=mid&&j<=q){
        if(L[i]<=R[j]) a[w++]=L[i++];
        else{
            cnt+=mid-i+1;
            a[w++]=R[j++];
        }
    }
    while(i<=mid) a[w++]=L[i++];
    while(j<=q) a[w++]=R[j++];
}
void mergeSort(int *a,int p,int q,ll &cnt){
    if(p<q){
        int mid=(p+q)>>1;
        mergeSort(a,p,mid,cnt);
        mergeSort(a,mid+1,q,cnt);
        merge(a,p,mid,q,cnt);
    }
}
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        ll cnt=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        mergeSort(a,0,n-1,cnt);
        cnt=cnt<=k?0:cnt-k;
        printf("%I64d\n",cnt);
    }
    return 0;
}

