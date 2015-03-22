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
#define CLR  memset(A,0,sizeof(A))
const int MOD=2009;
int main(){
    int n;
    while(cin>>n){
        if(n>=41) cout<<0<<endl;
        else{
            int sum=1;
            for(int i=1;i<=n;i++){
                sum=((sum%MOD)*(i%MOD))%MOD;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

