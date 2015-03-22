#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
const int MAXN=500000 + 10;
#define CLR(A) memset(A,0,sizeof(A))
struct Edge{
    int u,v,w;
}edge[MAXN];
int fa[MAXN],tot[MAXN],sum[MAXN],n,m;
int cnt=1;
vector<int> g;
void init(){
    g.clear();cnt=1;
    for(int i=0;i<MAXN;i++){
        fa[i]=i;sum[i]=1;tot[i]=0;
    }
}
bool cmp(Edge a,Edge b){
    return a.w<b.w;
}
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kruskal(){
    cnt=1;
    for(int i=0;i<m;i++){
        Edge e=edge[i];
        int x=find(e.u),y=find(e.v);
        if(x!=y){
            g.push_back(e.w);
            tot[cnt++]=sum[x]*sum[y]*2;
            sum[y]+=sum[x];
            fa[x]=y;
        }
    }
    for(int i=1;i<cnt;i++) tot[i]+=tot[i-1];
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        init();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+m,cmp);
        kruskal();
        int p;
        scanf("%d",&p);
        while(p--){
            int v;scanf("%d",&v);
            int tmp=lower_bound(g.begin(),g.end(),v)-g.begin();
          //  cout<<tmp<<endl;
            printf("%d\n",tot[cnt-1]-tot[tmp]);
        }
    }
    return 0;
}
