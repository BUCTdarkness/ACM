#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF=0xffffff0;
const int MAX=200010;
int minv=INF,maxv=-INF;
int cnt=0;
struct Node{
    int l,r;
    int minv,maxv;
    Node *left,*right;
}tree[MAX];
inline int Mid(Node *p){
	return (int)((p->l)+ (p->r))/2;
}
void buildTree(Node *p,int l,int r){
	p->l=l;p->r=r;
	p->minv=INF;p->maxv=-INF;
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
		p->minv=p->maxv=v;
		return;
	}
	p->minv=min(p->minv,v);
	p->maxv=max(p->maxv,v);
	if(i<=Mid(p)){
		insert(p->left,i,v);
	}
	else{
		insert(p->right,i,v);
	}
}
void query(Node *p,int a,int b){
	if(p->minv>=minv&&p->maxv<=maxv) return;
	if(p->l==a&&p->r==b){
		minv=min(minv,p->minv);
		maxv=max(maxv,p->maxv);
		return;
	}
	if(b<=Mid(p)) {
        query(p->left,a,b);
    }
	else if(a>Mid(p)) {
        query(p->right,a,b);
	}
	else{
		query(p->left,a,Mid(p));
		query(p->right,Mid(p)+1,b);
	}
}
int main(){
	int n,q,h;
	while(scanf("%d%d",&n,&q)!=EOF){
		cnt=0;
		buildTree(tree,1,n);
		int v;
		for(int i=1;i<=n;i++){
			scanf("%d",&v);
			insert(tree,i,v);
		}

		for(int i=0;i<q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			minv=INF;
			maxv=-INF;
			query(tree,a,b);
			printf("%d\n",maxv-minv);
		}
	}
    return 0;
}
