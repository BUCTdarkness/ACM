//#pragma comment(linker, "/STACK:36777216")
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
#define CLR(A,B) memset(A,B,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
#define long long ll
#define MP(A,B) make_pair(A,B)
const int MAXN=410;
const int MAXP=410;
int uN,vN;
bool g[MAXP][MAXN];
int xM[MAXN],yM[MAXN];
bool vis[MAXN];
struct Son{
    int index,v;
}son[MAXN];
bool cmp(Son a,Son b){
    return a.v>=b.v;
}
bool dfs(int u){
    for(int v=1;v<=vN;v++){
        if(!vis[v]&&g[u][v]){
            vis[v]=1;
            if(yM[v]==-1||dfs(yM[v])){
                yM[v]=u;xM[u]=v;
                return true;
            }
        }
    }
    return false;
}
bool MaxMatch(){
    int ret=0;
    CLR(xM,-1);CLR(yM,-1);
    for(int u=1;u<=uN;u++){
        int i=son[u].index;
        if(xM[i]==-1){
            CLR(vis,0);
            if(dfs(i)) ret++;
        }
    }
    return ret==uN?true:false;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        uN=vN=n;
        CLR(g,0);
        for(int i=1;i<=uN;i++){
            scanf("%d",&son[i].v);
            son[i].index=i;
        }
        sort(son+1,son+uN+1,cmp);
        for(int i=1;i<=uN;i++){
            int num;
            scanf("%d",&num);
            for(int j=1;j<=num;j++){
                int v;
                scanf("%d",&v);
                g[i][v]=1;
            }
        }
        MaxMatch();
        for(int i=1;i<=uN;i++){
            if(i==1) printf("%d",xM[i]==-1?0:xM[i]);
            else printf(" %d",xM[i]==-1?0:xM[i]);
        }
        puts("");
    }
    return 0;
}
