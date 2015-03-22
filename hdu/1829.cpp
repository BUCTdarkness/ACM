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
const int MAX=2006;
int p[MAX],rel[MAX];
int find_set(int v){
    if(p[v]==v) return v;
    int t=find_set(p[v]);
    rel[v]=(rel[v]+rel[p[v]])%2;
    return p[v]=t;
}
bool union_set(int x,int y){
    int a=find_set(x);
    int b=find_set(y);
    if(a==b){
        if(rel[x]==rel[y]) return true;
        return false;
    }
    p[a]=b;
    rel[a]=(rel[x]+rel[y]+1)%2;
    return false;
}
int main(){
    int t;
    while(cin>>t){
        for(int cas=1;cas<=t;cas++){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=0;i<=n;i++){
                p[i]=i;rel[i]=0;
            }
            bool flag=false;
            while(m--){
                int a,b;
                scanf("%d%d",&a,&b);
                if(flag) continue;
                flag=union_set(a,b);
            }
            printf("Scenario #%d:\n",cas);
            if(flag) printf("Suspicious bugs found!\n\n");
            else printf("No suspicious bugs found!\n\n");
        }
    }
    return 0;
}

