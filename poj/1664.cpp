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
int f(int m,int n){
    if(m==0||n==1) return 1;
    if(m<n) return f(m,m);
    return f(m-n,n)+f(m,n-1);
}
int main(){
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            int m,n;
            scanf("%d%d",&m,&n);
            cout<<f(m,n)<<endl;
        }
    }
    return 0;
}

