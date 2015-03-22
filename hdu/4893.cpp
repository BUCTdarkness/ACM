#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=400010;
struct Node{
    int l,r;
    ll v;
}tree[MAX];
ll f[100];
int del[MAX];
void build(int id,int l,int r){
    tree[id].l=l;tree[id].r=r;tree[id].v=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
}
void add(int id,int i,ll v){
    if(tree[id].l==tree[id].r){
        tree[id].v+=v;
        return;
    }
    int m=(tree[id].l+tree[id].r)>>1;
    if(i<=m) add(id<<1,i,v);
    else add(id<<1|1,i,v);
    tree[id].v=tree[id<<1].v+tree[id<<1|1].v;
}
ll query(int id,int l,int r){
    if(l==tree[id].l&&r==tree[id].r) return tree[id].v;
    int m=(tree[id].l+tree[id].r)>>1;
    if(r<=m) return query(id<<1,l,r);
    if(l>m) return query(id<<1|1,l,r);
    return query(id<<1,l,m)+query(id<<1|1,m+1,r);
}
void init(){
    CLR(f);
    f[0]=1;f[1]=1;
    for(int i=2;i<=91;i++) f[i]=f[i-1]+f[i-2];
}
int main(){
    int n,m;
    init();
    while(~scanf("%d%d",&n,&m)){
        build(1,1,n);
        set<int>st;
        set<int>::iterator it;
        for(int i=1;i<=n;i++) st.insert(i);
        while(m--){
            int ord,a,b;
            scanf("%d%d%d",&ord,&a,&b);
            switch(ord){
                case 1:
                    add(1,a,b);
                    st.insert(a);
                    break;
                case 2:
                    printf("%I64d\n",query(1,a,b));
                    break;
                case 3:
                    it=lower_bound(st.begin(),st.end(),a);
                    del[0]=0;
                    for(;it!=st.end()&&((*it)<=b);it++){
                        int p=*it;
                        del[++del[0]]=p;
                        ll u=query(1,p,p),k;
                        int t=lower_bound(f+1,f+92,u)-f;
                        if(abs(f[t]-u)<abs(f[t-1]-u)) k=f[t];
                        else k=f[t-1];
                        add(1,p,-u);add(1,p,k);
                    }
                    for(int i=1;i<=del[0];i++) st.erase(del[i]);
                    break;
                default:;
            }
        }
    }
    return 0;
}
