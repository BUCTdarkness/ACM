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
int main(){
    ll n,k;
    int ncase=0;
    while(cin>>n>>k&&(n+k)){
         ll tmp=n;
         for(ll i=2;i<=k;i++){
            tmp=tmp-tmp/i;
            if(tmp<i) break;
         }
         printf("Case #%d: %I64d\n",++ncase,tmp*k);
    }
    return 0;
}
