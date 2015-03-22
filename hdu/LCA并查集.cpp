#include<bits/stdc++.h>
using namespace std;
const int N=100100;
typedef unsigned int uint;
typedef pair<int,int> P;
vector<int>G[N];
map<string,int> H;
vector<P > Q[N];
string a,b,m[N];
int A,B,p[N],n,c,L[N];
int find(int i){return p[i]==i?i:p[i]=find(p[i]);}
void dfs(int u,int par){
    p[u]=u;
    int v;
    for(int i=0;i<G[u].size();i++) if((v=G[u][i])!=par) dfs(v,u);
    for(int i=0;i<Q[u].size();i++) if(p[Q[u][i].first]) L[Q[u][i].second]=find(p[Q[u][i].first]);
    p[u]=par;
}
int main(){
    cin>>n;
    int cc=0;
    while(n--){
        cin>>a>>b;
        if(!(A=H[a])) A=H[a]=++cc,m[cc]=a;
        if(!(B=H[b])) B=H[b]=++cc,m[cc]=b;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        A=H[a];B=H[b];
        Q[A].push_back(P(B,i));
        Q[B].push_back(P(A,i));
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) cout<<m[L[i]]<<endl;
    return 0;
}
