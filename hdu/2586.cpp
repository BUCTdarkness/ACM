#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
const int MAX=40010;
struct Edge{
    int from,to,val,next;
}edge[MAX*2];
int deep[MAX],dis[MAX],fa[MAX],ace[MAX],head[MAX];
int n,m,cnt=0;
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;
    memset(fa,0,sizeof(fa));
}
inline void addEdge(int a,int b,int v){
    edge[cnt].from=a;edge[cnt].to=b;edge[cnt].val=v;
    edge[cnt].next=head[a];
    head[a]=cnt++;
}
int find(int x,int y){
    if(x==y) return x;
    if(deep[x]>deep[y]) return find(fa[x],y);
    else return find(x,fa[y]);
}
void dfs(int now,int now_fa,int now_ace,int now_deep,int now_dis){
    fa[now]=now_fa;deep[now]=now_deep;ace[now]=now_ace;dis[now]=now_dis;
    for(int i=head[now];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        if(fa[v]==0){
            dfs(v,now,now_ace,now_deep+1,now_dis+edge[i].val);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int a,b,c;
        init();
        for(int i=0;i<n-1;i++){
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);addEdge(b,a,c);
        }
        for(int i=1;i<=n;i++){
            if(fa[i]==0) dfs(i,-1,i,0,1);
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(ace[a]==ace[b]){
                int f=find(a,b);
                cout<<a<<" "<<b<<" "<<f<<" "<<ace[a]<<endl;
                printf("%d\n",dis[a]+dis[b]-2*dis[f]);
            }
            else{
                puts("Not connected");
            }
        }
       // printf("\n");
    }
    return 0;
}

