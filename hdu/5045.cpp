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
#define typef int
#define typec double
const typef inff = 0x3f3f3f3f;
const typec infc = 0x3f3f3f3f;
const int E=1010;
const int N=100;
class network
{
public:
    int nv, ne, pnt[E], nxt[E];
    int vis[N], que[N], head[N], pv[N], pe[N];
    typec cost, dis[E], d[N];typef flow, cap[E];
    void addedge(int u, int v, typef c, typec w) {
        pnt[ne] = v; cap[ne] = c;
        dis[ne] = +w; nxt[ne] = head[u]; head[u] = ne++;
        pnt[ne] = u; cap[ne] = 0;
        dis[ne] = -w; nxt[ne] = head[v]; head[v] = ne++;
    }
    double mincost(int src, int sink) {
        int i, k, f, r; typef mxf;
        for (flow = 0, cost = 0; ; ) {
            memset(pv, -1, sizeof(pv));
            memset(vis, 0, sizeof(vis));
            for (i = 0; i < nv; ++i) d[i] = infc;
            d[src] = 0; pv[src] = src; vis[src] = 1;
            for (f = 0, r = 1, que[0] = src; r != f; ) {
                i = que[f++]; vis[i] = 0;
                if (N == f) f = 0;
                for (k = head[i]; k != -1; k = nxt[k])
                if(cap[k] && dis[k]+d[i] < d[pnt[k]]){
                    d[pnt[k]] = dis[k] + d[i];
                    if (0 == vis[pnt[k]]) {
                        vis[pnt[k]] = 1;
                        que[r++] = pnt[k];
                        if (N == r) r = 0;
                    }
                    pv[pnt[k]]=i; pe[pnt[k]]=k;
                }
            }
            if (-1 == pv[sink]) break;
            for (k = sink, mxf = inff; k != src; k = pv[k])
                if (cap[pe[k]] < mxf) mxf = cap[pe[k]];
                    flow += mxf; cost += d[sink] * mxf;
            for (k = sink; k != src; k = pv[k]) {
                cap[pe[k]] -= mxf; cap[pe[k] ^ 1] += mxf;
            }
        }
        return cost;
    }
    void build(int v) {
        nv = v; ne = 0;
        memset(head, -1, sizeof(head));
    }
};network g;
int m,n; //n 人数   m题数
double So[20][1010];
double solve(int x,int y){
  //  cout<<"ST SOLVE"<<endl;
    double ret=0;
    int Pro=y-x+1;
    int nv=n+Pro+1;
 //   cout<<"Pro="<<Pro<<' '<<"nv="<<nv<<' '<<"n="<<n<<endl;
    g.build(nv+1);
    for(int i=1;i<=n;i++)
        g.addedge(0,i,1,0);
    for(int i=n+1;i<=n+Pro;i++)
        g.addedge(i,nv,1,0);
    for(int i=1;i<=n;i++)
        for(int j=n+1;j<=n+Pro;j++){
            g.addedge(i,j,1,-So[i][j-n-1+x]);
        }
    ret=g.mincost(0,nv);
    return ret;
}
int main(){

    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif
    int T,kase=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%lf",&So[i][j]);
            }
        }
        double ans=0.0;int t=0;
        for(int i=1;i<=m;i+=n){
            ans+=solve(i,min(m,i+n-1));
        }
        printf("Case #%d: %.5lf\n",++kase,-ans);
    }
    return 0;
}