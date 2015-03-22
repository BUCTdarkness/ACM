#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
int change(int a,int b,int c){
    return a*3600+b*60+c;
}
struct Node{
    int v,pos;
};
bool cmp(Node a,Node b){
    if(a.v==b.v) return a.pos<b.pos;
    return a.v<b.v;
}
int main(){
    int T;
    while(cin>>T){
        while(T--){
            int n,t,pre=0,cnt=1;
            vector<int> g;
            vector<Node> p;
            p.clear();g.clear();
            scanf("%d%d",&n,&t);
            for(int i=0;i<n;i++){
                int a,b,c;
                scanf("%d:%d:%d",&a,&b,&c);
                int tmp=change(a,b,c);
                p.push_back((Node){tmp,i+1});
            }
            sort(p.begin(),p.end(),cmp);
            pre=p[0].v;
            g.push_back(p[0].pos);
            for(int i=1;i<p.size();i++){
                int tmp=p[i].v;
                if(pre+t<=tmp){
                    cnt++;
                    g.push_back(p[i].pos);
                    pre=tmp;
                }
            }
            cout<<cnt<<endl;
            sort(g.begin(),g.end());
            for(int i=0;i<g.size();i++){
                if(i!=0) cout<<" ";
                cout<<g[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
