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
const int MAX=32005;
int level[MAX];
struct Node{
    int l,r,v;
}tree[MAX*4];
inline void pushup(int id){tree[id].v=tree[id<<1].v+tree[id<<1|1].v;}
void build(int id,int l,int r){
    tree[id].l=l;tree[id].r=r;tree[id].v=0;
    if(l==r) return;
    int m=(l+r)>>1;
    build(id<<1,l,m);
    build(id<<1|1,m+1,r);
}
void add(int id,int i,int v){
    if(tree[id].l==tree[id].r) {
        tree[id].v+=v;
        return;
    }
    int m=(tree[id].l+tree[id].r)>>1;
    if(i<=m) add(id<<1,i,v);
    else add(id<<1|1,i,v);
    pushup(id);
}
int query(int id,int l,int r){
    if(l==tree[id].l&&r==tree[id].r) return tree[id].v;
    int m=(tree[id].l+tree[id].r)>>1;
    if(r<=m) return query(id<<1,l,r);
    else if(l>m) return query(id<<1|1,l,r);
    else return query(id<<1,l,m)+query(id<<1|1,m+1,r);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        CLR(level);
        build(1,1,MAX);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            int tmp=query(1,1,x+1);
            level[tmp]++;
            add(1,x+1,1);
        }
        for(int i=0;i<n;i++){
            printf("%d\n",level[i]);
        }
    }
    return 0;
}
