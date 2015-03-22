#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define CPY(A,B) memset(A,B,sizeof(B))
int val[110];
vector<int> g[110];
bool vis[110];
int ret=0,end;
void dfs(int u){
    int ma=-1,mp=0;
    for(int i=0;i<g[u].size();i++){
        if(!vis[g[u][i]]&&ma<g[u][i]){
            mp=g[u][i];
            ma=val[mp];
        }
    }
    vis
    dfs(mp);
}
int main(){
    int t;
    while(cin>>t){
        int ncase=0;
        while(t--){
            int n,m;
            scanf("%d%d",&n,m);
            for(int i=0;i<n;i++){
                scanf("%d",&val[i]);
            }
            while(m--){
                int u,v;
                scanf("%d%d",&u,&v);
                g[u].push_back(v);
            }

        }
    }
    return 0;
}
