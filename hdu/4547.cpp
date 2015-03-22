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
const int MAX=100010;
struct Edge{
    int from,to,next;
}edge[MAX*2];
int deep[MAX],fa[MAX],ace[MAX],head[MAX];
int cnt;
map<string,int> mp;
void init(){
    memset(head,-1,sizeof(head));
    cnt=0;CLR(fa);mp.clear();
}
void addEdge(int a,int b){
    edge[cnt].from=a;edge[cnt].to=b;
    edge[cnt].next=head[a];
    head[a]=cnt++;
}
int find(int x,int y){
    if(x==y) return x;
    if(deep[x]>deep[y]) return find(fa[x],y);
    else return find(x,fa[y]);
}
void dfs(int now,int now_fa,int now_ace,int now_deep){
    fa[now]=now_fa;deep[now]=now_deep;ace[now]=now_ace;
    for(int i=head[now];i!=-1;i=edge[i].next){
        int v=edge[i].to;
        dfs(v,now,now_ace,now_deep+1);
    }
}

int main(){
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        int cntt=1;
        string a,b;
        for(int i=0;i<n-1;i++){
            cin>>a>>b;
            if(mp[a]==0) mp[a]=cntt++;
            if(mp[b]==0) mp[b]=cntt++;
            addEdge(mp[b],mp[a]);
        }
        for(int i=1;i<cntt;i++){
            if(fa[i]==0) {dfs(i,-1,i,0);}
        }
        while(m--){
            cin>>a>>b;
            int t1=mp[a],t2=mp[b];
            int f=find(t1,t2);
            if(f==t2) printf("%d\n",abs(deep[t2]-deep[t1]));
            else if(f==t1) printf("1\n");
            else printf("%d\n",abs(deep[t1]-deep[f])+1);
        }
    }
    return 0;
}
