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
const int MAXE=15010;
const int MAXV=1010;
struct Edge{
    int s,e,w;
}e[MAXE];
int p[MAXV];
bool cmp(Edge a,Edge b){return a.w<b.w;}
int find_set(int a){return p[a]==a?a:p[a]=find_set(p[a]);}
bool union_set(int x,int y){
    x=find_set(x);y=find_set(y);
    if(x!=y){
        p[x]=p[y];
        return true;
    }
    return false;
}
int init(){
    for(int i=0;i<MAXV;i++){p[i]=i;}
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(int i=0;i<m;i++) scanf("%d%d%d",&e[i].s,&e[i].e,&e[i].w);
        sort(e,e+m,cmp);
        int ans=-1,cnt=0;
        vector<Edge> g;
        for(int i=0;i<m;i++){
            if(union_set(e[i].s,e[i].e)){
                ans=max(ans,e[i].w);
                g.push_back(e[i]);
                if(++cnt==(n-1))break;
            }
        }
        printf("%d\n",ans);
        printf("%d\n",g.size());
        for(int i=0;i<g.size();i++){
            printf("%d %d\n",g[i].s,g[i].e);
        }
    }
    return 0;
}
