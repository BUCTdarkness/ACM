#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=13;
int vis[MAX],ma[MAX],mat[MAX][MAX],mi[MAX],smi[MAX],sma[MAX];
int N,M;
int cnt=0;
int gcd(int x,int y ){
    if(x < y) return gcd(y,x);  // x>y
    if( y == 0) return x;  // if y=0, x is GCD
    else{
         if( !(x%2) ){
           if( !(y%2) )  //x,y both even
               return 2*gcd(x >> 1, y >> 1);
           else      // x is even, y is odd
               return gcd(x >> 1, y );
         }
         else {
           if( !(y%2) )  // x is  odd,  y is even
               return gcd(x, y >> 1);
           else       // x, y both odd
               return gcd(y,x-y);
         }
    }
}
void dfs(int h,int sum){
    if(sum>=M){
        cnt++;
        return;
    }
    if(sum+smi[h]>=M){
        int t=N-h;
        int s=1;
        for(int i=1;i<=t;i++) s*=i;
        cnt+=s;
        return;
    }
    if(h>=N){
        if(sum>=M){
            cnt++;
            return;
        }
    }
    if(h<N&&sum+sma[h]<M) return;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(h+1,sum+mat[h][i]);
            vis[i]=false;
        }
    }
}
void init(){
    CLR(vis);CLR(ma);CLR(mat);CLR(smi);CLR(sma);
    for(int i=0;i<N;i++){mi[i]=1<<30;}
    cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&mat[i][j]);
            ma[i]=max(ma[i],mat[i][j]);
            mi[i]=min(mi[i],mat[i][j]);
        }
    }
  //  for(int i=0;i<N;i++) cout<<mi[i]<<endl;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            smi[i]+=mi[j];
            sma[i]+=ma[j];
        }
    }
//    for(int i=0;i<N;i++){
//        cout<<smi[i]<<" "<<sma[i]<<endl;
//    }
}
int main(){
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d%d",&N,&M);
            init();
            ll sum=0;
            for(int i=0;i<N;i++){
                sum+=ma[i];
            }
            if(sum<M){
                printf("No solution\n");
                continue;
            }
            dfs(0,0);
            if(cnt==0){
                printf("No solution\n");
            }
            else{
                int nh=1;
                for(int i=1;i<=N;i++) nh*=i;
                int d=gcd(nh,cnt);
                printf("%d/%d\n",nh/d,cnt/d);
            }
        }
    }
    return 0;
}

