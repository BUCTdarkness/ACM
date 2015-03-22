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
const int MAX=50010;
int p[MAX];
bool vis[MAX];
void init(){
    for(int i=0;i<MAX;i++) p[i]=i;
}
int find_set(int a){
    return p[a]==a?a:p[a]=find_set(p[a]);
}
void union_set(int a,int b){
    a=find_set(a);b=find_set(b);
    if(a!=b){
        p[a]=p[b];
    }
}

int main(){
    int n,m,cas=0;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        init();
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            union_set(u,v);
        }
        CLR(vis);
        int cnt=0;
        for(int i=1;i<=n;i++){
            int tmp=find_set(i);
            if(!vis[tmp]){
                vis[tmp]=true;
                cnt++;
            }
        }
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}

