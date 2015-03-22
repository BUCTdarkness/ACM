#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int main(){
    int n;
    while(~scanf("%d",&n)){
        long long sum=0,a,b;
        long long maxv=0;
        while(n--){
            scanf("%lld%lld",&a,&b);
            sum+=(a-b);
            maxv=max(maxv,a-b);
        }
        if(sum&1||2*maxv>sum){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}

