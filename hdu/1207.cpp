#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
int solve(int n){
    int cnt=1;
    while(n!=1){
        if(n%2!=0) n=3*n+1;
        else n/=2;
        cnt++;
    }
    return cnt;
}
int main(){
    int x,y;
    while(cin>>x>>y){
        if(x>y){ int t=x;x=y;y=t;}
        int ret=0;
        for(int i=x;i<=y;i++){
            int tmp=solve(i);
            if(ret<tmp) ret=tmp;
        }
        cout<<x<<' '<<y<<' '<<ret<<endl;
    }
    return 0;
}
