#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int INF=0xffffff0;
const int MAX=800010;
struct Node{
	int l,r;
	int minv,maxv;
	int Mid(){
		return (l+r)/2;
	}
}tree[MAX];
int minv,maxv;
void buildtree(int root,int l,int r){
	tree[root].l=l;tree[root].r=r;
	tree[root].minv=INF;tree[root].maxv=-INF;
	if(l==r) return;
	buildtree(2*root+1,l,(l+r)/2);
	buildtree(2*root+2,(l+r)/2+1,r);
}
void insert(int root,int i,int v){
	if(tree[root].l==tree[root].r){
		tree[root].minv=tree[root].maxv=v;
		return;
	}
	tree[root].minv=min(tree[root].minv,v);
	tree[root].maxv=max(tree[root].maxv,v);
	if(i<=tree[root].Mid()) insert(2*root+1,i,v);
	else insert(2*root+2,i,v);
}
void query(int root,int l,int r){
	if(tree[root].minv>=minv&&tree[root].maxv<=maxv) return;
	if(tree[root].l==l&&tree[root].r==r){
		minv=min(minv,tree[root].minv);
		maxv=max(maxv,tree[root].maxv);
		return;
	}
	if(r<=tree[root].Mid()) query(2*root+1,l,r);
	else if(l>tree[root].Mid()) query(2*root+2,l,r);
	else{
		query(2*root+1,l,tree[root].Mid());
		query(2*root+2,tree[root].Mid()+1,r);
	}
}
int main(){
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		buildtree(0,1,n);
		for(int i=1;i<=n;i++){
			int v;
			scanf("%d",&v);
			insert(0,i,v);
		}
		for(int i=0;i<q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			minv=INF;
			maxv=-INF;
			query(0,a,b);
			printf("%d\n",maxv-minv);
		}
	}
	return 0;
}

