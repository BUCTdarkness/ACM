#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=8010;
struct Node{
    int l,r,len,v;
}tree[MAX*4];
int ans[MAX];
int f[MAX];
inline void pushup(int id){
    tree[id].len=tree[id<<1].len+tree[id<<1|1].len;
}
void build(int id,int l,int r){
    tree[id].l=l;tree[id].r=r;
    if(l==r){
        tree[id].v=l;
        tree[id].len=1;
        return;
    }
    int m=(l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
    pushup(id);
}
void query(int id,int cur,int pos){
    if(tree[id].l==tree[id].r){
        tree[id].len=0;
        ans[pos]=tree[id].v;
        return;
    }
    if(tree[id<<1].len>=cur) query(id<<1,cur,pos);
    else query(id<<1|1,cur-tree[id<<1].len,pos);
    pushup(id);
}
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        for(int i=2;i<=n;i++){
            scanf("%d",&f[i]);
            f[i]++;
        }
        build(1,1,n);
        f[1]=1;
        for(int i=n;i>=1;i--){
            query(1,f[i],i);
        }
        for(int i=1;i<=n;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
