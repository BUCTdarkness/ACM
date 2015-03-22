#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
    int kase=0;
    long long h,a,b,k;
    while(cin>>h>>a>>b>>k){
        if(h==0 && a==0 && b==0 && k==0){
            break;
        }
        if(h<=a){
            printf("Case #%d: YES\n",++kase);
            continue;
        }
        if(a<=b){
            printf("Case #%d: NO\n",++kase);
            continue;
        }
        if((a-b)*k>=(h-b)){
            printf("Case #%d: YES\n",++kase);
            continue;
        }
        if((a-b)*k-b>0){
            printf("Case #%d: YES\n",++kase);
            continue;
        }
        else{
            printf("Case #%d: NO\n",++kase);
        }
    }
    return 0;
}
