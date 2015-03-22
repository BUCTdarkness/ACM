#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#define MAXN 10010
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
vector<int>son[MAXN];
bool vis[MAXN];
int N,dp[MAXN],ans;
int work(int id){
    int sz=son[id].size();
    if(sz==0){
        dp[id]=1;
        return dp[id];
    }
    for(int i=0;i<sz;i++){
        int v=son[id][i];
        if(vis[v])    continue;
        vis[v]=1;
        work(v);
    }
    if(sz==1){
        dp[id]=dp[son[id][0]];
        return dp[id];
    }
    if(sz==2){
        int u=son[id][0],v=son[id][1];
        int t1=dp[u],t2=dp[v];
        if(t1==t2)
            dp[id]=dp[u]+1;
        else
            dp[id]=max(t1,t2);
        return dp[id];
    }
}
int main(){
    while(~scanf("%d",&N)){
        int x;
        for(int i=0;i<=N+1;i++)
            son[i].clear();
        for(int i=2;i<=N;i++){
            scanf("%d",&x);
            son[x].push_back(i);
//           son[x].push_back(i);
        }
        CLR(vis);CLR(dp);
        vis[1]=1;
        ans=work(1);
        printf("%d\n",ans);
    }
    return 0;
}
