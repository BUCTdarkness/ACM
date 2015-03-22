#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int ans[100010];
struct Line{
    int u,v;
}f[100100];
int p[10010];
int find_set(int x){
    return p[x]==x?x:p[x]=find_set(p[x]);
}
int union_set(int x,int y){
    int u=find_set(x),v=find_set(y);
    if(u==v) return 0;
    p[u]=v;
    return 1;
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=m;i++) scanf("%d%d",&f[i].u,&f[i].v);
        ans[m]=n;
        for(int i=0;i<n;i++) p[i]=i;
        for(int i=m;i>=1;i--){
            ans[i-1]=ans[i]-union_set(f[i].u,f[i].v);
        }
        for(int i=1;i<=m;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}

