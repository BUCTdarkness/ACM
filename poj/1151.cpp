#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
double y[210];
struct Node {
	double len;
	int l,r,cover;
	Node *left,*right;
}tree[1010];
struct Cline{
	double x,y1,y2;
	bool bleft;
}line[210];
bool cmp(Cline a,Cline b){return a.x<b.x;}
template<class F,class T>
F bin_search(F a,F b,T val){
	F l=a,r=b-1;
	while(l<=r){
		F mid=l+(r-l)/2;
		if(!(*mid<val||val<*mid)) return mid;
		else if(val<*mid) r=mid-1;
		else l=mid+1;
	}
	return b;
}
inline int Mid(Node *p){return (p->l+p->r)/2;}


int cnt=0;


void buildTree(Node *p,int l,int r){
	p->l=l;p->r=r;
	p->len=0;
	p->cover=0;
	if(l==r) return;
	cnt++;
	p->left=tree+cnt;
	cnt++;
	p->right=tree+cnt;
	buildTree(p->left,l,(l+r)/2);
	buildTree(p->right,(l+r)/2+1,r);
}
void insert(Node *p,int l,int r){
	if(p->l==l&&p->r==r){
		p->len=y[r+1]-y[l];
		p->cover++;
		return;
	}
	if(r<=Mid(p)) insert(p->left,l,r);
	else if(l>Mid(p)) insert(p->right,l,r);
	else{
		insert(p->left,l,Mid(p));
		insert(p->right,Mid(p)+1,r);
	}
	if(p->cover==0){
		p->len=p->left->len+p->right->len;
	}
}
void del(Node *p,int l,int r){
	if(p->l==l&&p->r==r){
		p->cover--;
		if(p->cover==0){
			if(p->l==p->r) p->len=0;
			else p->len=p->left->len+p->right->len;
		}
		return;
	}
	if(r<=Mid(p)) del(p->left,l,r);
	else if(l>Mid(p)) del(p->right,l,r);
	else{
		del(p->left,l,Mid(p));
		del(p->right,Mid(p)+1,r);
	}
	if(p->cover==0){
		p->len=p->left->len+p->right->len;
	}
}
int main(){
	int n,ncas=0;
	double x=1.0000;
	x=x/6.002;cout<<x<<endl;x=x*(2.000+1.001);
	if(x==0.5)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
	while(scanf("%d",&n)!=NULL&&n){
		ncas++;
		cnt=0;
		int yc=0,lc=0;
		for(int i=0;i<n;i++){
			double x1,x2,y1,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			y[yc++]=y1;y[yc++]=y2;
			line[lc].x=x1;line[lc].y1=y1;line[lc].y2=y2;
			line[lc++].bleft=true;
			line[lc].x=x2;line[lc].y1=y1;line[lc].y2=y2;
			line[lc++].bleft=false;
		}
		sort(y,y+yc);
		sort(line,line+lc,cmp);
		yc=unique(y,y+yc)-y;
		buildTree(tree,0,yc-2);
		double ret=0;
		for(int i=0;i<lc-1;i++){
			int l=bin_search(y,y+yc,line[i].y1)-y;
			int r=bin_search(y,y+yc,line[i].y2)-y;
			if(line[i].bleft) insert(tree,l,r-1);
			else del(tree,l,r-1);
			ret+=tree[0].len*(line[i+1].x-line[i].x);
		}
//		printf("Test case #%d\n",ncas);
//		printf("Total explored area: %.2lf\n",ret );
		printf("Test case #%d\n",ncas);
        printf("Total explored area: %.2f\n",ret);
        printf("\n");
	}
	return 0;
}
