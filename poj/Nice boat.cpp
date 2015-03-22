#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=100010;
struct Node{
    int Q;
    int l,r,x;
}t[MAX];
int a[MAX];
int gcd(int x,int y){
    if(y==0) return x;
    else return(gcd(y,x%y));
}
void solve(int Q,int i,int x){
    switch(Q){
    case 1:a[i]=x; break;
    case 2:a[i]=a[i]>x?gcd(a[i],x):a[i];break;
    }

}
int main(){
    int T,n,m;
    while(cin>>T){
        while(T--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            scanf("%d",&m);
            for(int i=0;i<m;i++){
                scanf("%d%d%d%d",&t[i].Q, &t[i].l, &t[i].r , &t[i].x);
            }
            for(int i=1;i<=n;i++){
                int j;
                for(j=m-1;j>=0;j--){
                    if(t[j].Q==1&&t[j].l<=i&&t[j].r>=i){
                        break;
                    }
                }
                int k=j;
                solve(t[k].Q,i,t[k].x);
                for(int h=k+1;h<m;h++){
                    if(a[i]==1) break;
                    if(t[h].l<=i&&t[h].r>=i) solve(t[h].Q,i,t[h].x);
                }
                printf("%d ",a[i]);
            }

            printf("\n");
        }
    }
    return 0;
}
