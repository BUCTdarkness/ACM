#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const int INF=0xffffff0;
const int MAX=200010;
int cnt=0;
struct Node{
    int l,r;
    Node *left,*right;
    ll sum,inc;
}tree[MAX];
inline int Mid(Node *p){return (int)((p->l)+(p->r))/2;}
void buildTree(Node *p,int l,int r){
    p->l=l;p->r=r;
    p->sum=0;p->inc=0;
    if(l==r) return;
    cnt++;
    p->left=tree+cnt;
    cnt++;
    p->right=tree+cnt;
    buildTree(p->left,l,(l+r)/2);
    buildTree(p->right,(l+r)/2+1,r);
}
void insert(Node *p,int i,int v){
    if(p->l==i&&p->r==i){
        p->sum=v;
        return;
    }
    p->sum+=v;
    if(i<=Mid(p)) insert(p->left,i,v);
    else insert(p->right,i,v);
}
void add(Node *p,int a,int b,ll c){
    if(p->l==a&&p->r==b){
        p->inc+=c;
        return;
    }
    p->sum+=c*(b-a+1);
    if(b<=Mid(p)) add(p->left,a,b,c);
    else if(a>Mid(p)) add(p->right,a,b,c);
    else{
        add(p->left,a,Mid(p),c);
        add(p->right,Mid(p)+1,b,c);
    }
}

ll query(Node *p,int a,int b){
    if(p->l==a&&p->r==b){
        return p->sum+(p->r-p->l+1)*p->inc;
    }
    p->sum+=(p->r-p->l+1)*p->inc;
    add(p->left,p->l,Mid(p),p->inc);
    add(p->right,Mid(p)+1,p->r,p->inc);
    p->inc=0;
    if(b<=Mid(p)) return query(p->left,a,b);
    else if(a>Mid(p)) return query(p->right,a,b);
    else{
        return query(p->left,a,Mid(p))+query(p->right,Mid(p)+1,b);
    }
}
int main(){
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){
        cnt=0;
        buildTree(tree,1,n);
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            insert(tree,i,a);
        }
        char cmd[10];
        int a,b,c;
        for(int i=0;i<q;i++){
            scanf("%s",cmd);
            if(cmd[0]=='C'){
                scanf("%d%d%d",&a,&b,&c);
                add(tree,a,b,c);
            }
            else{
                scanf("%d%d",&a,&b);
                printf("%I64d\n",query(tree,a,b) );
            }
        }

    }
    return 0;
}

