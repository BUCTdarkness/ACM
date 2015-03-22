#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
using namespace std;
const int MAX=100010;
int s[MAX],t[MAX];
bool check(int a[],int b[],int n){
    int i;
    for(i=0;i<n-1;i++){
        if((a[i]==a[i+1]&&b[i]==b[i+1])||(a[i]<a[i+1]&&b[i]<b[i+1])||(a[i]>a[i+1]&&b[i]>b[i+1]))
            continue;
        else break;
    }
    if(i==n-1) return true;
    else return false;
}
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=0;i<n;i++) scanf("%d",&s[i]);
        for(int i=0;i<m;i++) scanf("%d",&t[i]);
        int ans=0;
        for(int i=0;i<n-m+1;){
            if(check(&s[i],t,m)){
                i+=m;ans++;
            }
            else{
                i++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

