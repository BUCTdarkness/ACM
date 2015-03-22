#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
int sum,a[100];
bool vis[100];
bool cmp(int a,int b){return a>b;}
int dfs(int len,int n,int stick,int ret){
    if(stick==n&&ret==0) return len;
    if(ret==0) ret=len;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(a[i]>ret) continue;
        vis[i]=true;
        if(dfs(len,n,stick+1,ret-a[i])) return len;
        vis[i]=false;
        if(ret==a[i]||len==ret) break;
        while(a[i]==a[i+1]) i++;
    }
    return 0;
}
int main(){
    int n;
    while(cin>>n&&n){
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];sum+=a[i];
        }
        sort(a,a+n,cmp);
        int k;
        for(int i=1;i<=sum;i++){
            if(sum%i) continue;
            CLR(vis);
            k=dfs(i,n,0,i);
            if(k) break;
        }
        cout<<k<<endl;
    }
    return 0;
}
