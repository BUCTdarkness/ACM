//人生中写得最短的一个spfa了。。。
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cstdlib>
#define CLR(A) memset(A,0,sizeof(A))
using namespace std;
struct Node{
    int k,w;
};
bool operator <(const Node &a,const Node &b){return a.w>b.w;}
priority_queue<Node> q;
vector<vector<Node> > g;
bool used[30010]={0};
int main(){
    int n,m;
    Node p;
    while(~scanf("%d%d",&n,&m)){
        g.clear();
        g.resize(n+1);
        CLR(used);
        for(int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            p.k=b;p.w=c;
            g[a].push_back(p);
        }
        p.k=1;p.w=0;
        q.push(p);
        while(!q.empty()){
            p=q.top();q.pop();
            if(used[p.k]) continue;
            used[p.k]=true;
            if(p.k==n) break;
            Node tmp;
            for(int i=0;i<g[p.k].size();i++){
                tmp.k=g[p.k][i].k;
                if(used[tmp.k]) continue;
                tmp.w=p.w+g[p.k][i].w;
                q.push(tmp);
            }
        }
        printf("%d\n",p.w);
    }
    return 0;
}
