//最大团问题，可以用原图节点数减去其补图的二分匹配
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<cstdlib>
#define CLR(A) memset(A,0,sizeof(A))
using namespace std;
const int MAX = 210;
int b,g,m,link[MAX];
bool mp[MAX][MAX], vis[MAX];
bool dfs(int u){
    for(int i = 1; i <= b; i ++)
        if(!vis[i] && !mp[u][i]){
            vis[i] = true;
            if(link[i] == -1 || dfs(link[i])){
                link[i] = u;
                return true;
            }
        }
    return false;
}
int main(){
    int ncase = 0;
    while(~scanf("%d%d%d",&g,&b,&m)&&g+b+m){
        CLR(mp);
        while(m --){
            int u, v;
            scanf("%d%d",&u,&v);
            mp[u][v]=1;
        }
        int t=0;
        memset(link, -1, sizeof(link));
        for(int i = 1; i <= g; i ++){
            memset(vis, 0, sizeof(vis));
            if(dfs(i)) t++;
        }
        cout<<"Case "<<++ncase<<": "<<g+b-t<< endl;
    }
    return 0;
}
