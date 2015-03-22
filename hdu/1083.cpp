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
const int MAXN=310;
const int MAXP=110;
int uN,vN;
bool g[MAXP][MAXN];
int xM[MAXN],yM[MAXN];
bool vis[MAXN];
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
        if(xM[u]==-1){
            CLR(vis,0);
            if(dfs(u)) ret++;
        }
    }
    return ret==uN?true:false;
}
int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        scanf("%d%d",&uN,&vN);
        CLR(g,0);
        for(int i=1;i<=uN;i++){
            int c_stu,v;
            scanf("%d",&c_stu);
            for(int j=1;j<=c_stu;j++){
                scanf("%d",&v);
                g[i][v]=1;
            }
        }
        if(MaxMatch()) puts("YES");
        else puts("NO");
    }
    return 0;
}

