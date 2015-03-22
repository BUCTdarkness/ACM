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
const int MAX=1010;
int p[MAX];
int find_set(int v){
    return p[v]==v?v:p[v]=find_set(p[v]);
}
void union_set(int a,int b){
    a=find_set(a);b=find_set(b);
    if(a!=b){
        p[a]=p[b];
    }
}
void init(){
    for(int i=0;i<MAX;i++){
        p[i]=i;
    }
}
int main(){
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            int n,m;
            scanf("%d%d",&n,&m);
            init();
            while(m--){
                int u,v;
                scanf("%d%d",&u,&v);
                union_set(u,v);
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(p[i]==i) cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}


