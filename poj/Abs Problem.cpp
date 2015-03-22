#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
void gao(int n){
    int k=n%4;
    int minv,maxv;
    if(k==0||k==3) minv=0;
    else minv=1;
    k=(n-1)%4;
    if(k==0||k==3) maxv=n;
    else maxv=n-1;
    cout<<minv<<" "<<maxv<<endl;
    for(int i=n;i>=1;i--){
        if(i==n) cout<<i;
        else cout<<" "<<i;
    }
    cout<<endl;
    for(int i=n-1;i>=1;i--){
        if(i==n-1) cout<<i;
        else cout<<" "<<i;
    }
    cout<<" "<<n<<endl;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n==1){
            cout<<1<<" "<<1<<endl;
            cout<<1<<endl;
            cout<<1<<endl;
            continue;
        }
        if(n==2){
            cout<<1<<" "<<1<<endl;
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<1<<endl;
            continue;
        }
        gao(n);
    }
    return 0;
}
