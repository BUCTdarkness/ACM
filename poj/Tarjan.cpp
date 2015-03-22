#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdlib>
#define CLR(A) memset(A,0,sizeof(A))
using namespace std;
const int MAX=200;
typedef vector<int> Edge;
vector<Edge> g(MAX);
bool vis[MAX];
int dfn[MAX],low[MAX],father[MAX];
bool blsCutVetext[MAX];
int ntime=0,n,m;
void Tarjan(int u,int fa){
    father[u]=fa;
    low[u]=dfn[u]=ntime++;
    for(int i=0;i<g[u].size();i++){EBOD-311
        int v=g[u][i];
        if(!dfn[v]){
            Tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(fa!=v){
            low[u]=min(low[u],dfn[v]);
        }
    }
}
void solve(){
    int nroot=0;
    Tarjan(1,0);
    for(int i=2;i<=n;i++){
        int v=father[i];
        if(v==1) nroot++;
        else{
            if(dfn[v]<=low[i]) blsCutVetext[v]=true;
        }
    }
    if(nroot>1) blsCutVetext[1]=true;
    for(int i=1;i<=n;i++)
        if(blsCutVetext[i]) cout<<i<<endl;
    for(int i=1;i<=n;i++){
        int v=father[i];
        if(v>0&&dfn[v]<low[i])
            cout<<v<<","<<i<<endl;
    }
}
int main(){
    while(cin>>n>>m){
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            g[v].push_back(u);g[u].push_back(v);
        }
        CLR(dfn);CLR(father);CLR(blsCutVetext);
        solve();
    }
    return 0;
}
