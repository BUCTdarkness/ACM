#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=110;
class TwoSet{
private:
    int n;
    vector<int> G[MAX*2];
    bool mark[MAX*2];
    int S[MAX*2],c;
public:
    TwoSet(){
        CLR(mark);
        c=0;
    }
    void init(int n){
        this->n=n;
        for(int i=0;i<2*n;++i) G[i].clear();
        CLR(mark);
        c=0;
    }
    bool dfs(int x){
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for(int i=0;i<G[x].size();++i){
            if(!dfs(G[x][i])) return false;
        }
        return true;
    }
    void add_diff(int u,int v){
        u*=2;v*=2;
        G[u].push_back(v+1);G[u+1].push_back(v);
        G[v].push_back(u+1);G[v+1].push_back(u);
    }
    bool solve(){
        for(int i=0;i<n*2;i+=2){
            if(!mark[i]&&!mark[i+1]){
                c=0;
                if(!dfs(i)){
                    while(c>0) mark[S[--c]]=false;
                    if(!dfs(i+1)) return false;
                }
            }
        }
        return true;
    }
}obj;
int n,g[MAX][MAX];
int main(){
    while(~scanf("%d",&n)){
        obj.init(n+1);
        CLR(g);
        for(int i=1,x;i<=n;i++){
            while(~scanf("%d",&x)&&x) g[i][x]=1;
        }
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(g[i][j]&&g[j][i]);
                else{
                    g[i][j]=g[j][i]=0;
                    obj.add_diff(i,j);
                }
            }
        }
        if(obj.solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}
