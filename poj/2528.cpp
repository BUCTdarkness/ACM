#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;
const int MAX=500010;
const int MAX_P=10100;
const int MAX_H=10000010;
struct Node{
	int l,r;
	Node *left,*right;
	bool cover;
}tree[MAX];
struct Poster{
	int l,r;
}poster[MAX_P];
int hash[MAX_H];
int x[MAX_H];
int cnt=0;
inline int Mid(Node *p){return (int)(p->l+p->r)/2;}
void buildTree(Node *p,int l,int r){
	p->l=l;p->r=r;
	p->cover=false;
	if(l==r) return;
	cnt++;
	p->left=tree+cnt;
	cnt++;
	p->right=tree+cnt;
	buildTree(p->left,l,(l+r)/2);
	buildTree(p->right,(l+r)/2+1,r);
}
bool insert(Node *p,int l,int r){
	if(p->cover) return false;
	if(p->l==l&&p->r==r){
		p->cover=true;
		return true;
	}
	bool ret;
	if(r<=Mid(p)) ret=insert(p->left,l,r);
	else if(l>=Mid(p)+1) ret=insert(p->right,l,r);
	else{
		bool b1=insert(p->left,l,Mid(p));
		bool b2=insert(p->right,Mid(p)+1,r);
		ret=b1|b2;
	}
	p->cover=p->left->cover & p->right->cover;
	return ret;
}

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		int ncas=0;
		while(t--){
			ncas++;
			int n,ncnt=0;
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d%d",&poster[i].l,&poster[i].r);
				x[ncnt++]=poster[i].l;
				x[ncnt++]=poster[i].r;
			}
			sort(x,x+ncnt);
			ncnt=unique(x,x+ncnt)-x;
			int ninter=0;
			for(int i=0;i<ncnt;i++){
				hash[x[i]]=ninter;
				if(i<ncnt-1){
					if(x[i+1]-x[i]==1) ninter++;
					else ninter+=2;
				}
			}
			buildTree(tree,0,ninter);
			int sum=0;
			for(int i=n-1;i>=0;i--){
				if(insert(tree,hash[poster[i].l],hash[poster[i].r])){
					sum++;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}

