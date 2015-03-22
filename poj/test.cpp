
struct Node{
	int l,r;
	int minv,maxv;
	Node *left,*right;
}tree[200010];
inline int Mid(Node *p){
	return (int)(p->l+p->r)>>1;
}
void buildTree(Node *p,int l,int r){
	p->l=l;p->r=r;
	p->minv=INF;p->maxv=INF;
	cnt++;
	p->left=tree+cnt;
	cnt++;
	p->right=tree+cnt;
	buildTree(p->left,l,(l+r)>>1);
	buildTree(p->right,(l+r)>>1+1,r);	
}
void insert(Node *p,int i,int v){
	if(p->l==i&&p->r==i){
		p->minv=p->maxv=v;
		return;
	}
	p->minv=min(p->minv,v);
	p->maxv=max(p->maxv,v);
	if(i<=Mid) insert(p->left,i,v);
	else insert(p->right,i,v);
}
void query(Node *p,int a,int b){
	if(p->minv>=minv&&p->maxv<=maxv) return;
	if(p->l==a&&p->r==b){
		minv=min(minv,p->minv);
		maxv=max(maxv,p->maxv);
		return;
	}
	if(b<=Mid(p)) query(p->left,a,b);
	else if(a>Mid(p)) query(p->right,a,b);
	else {
		query(p->left,a,Mid(p));
		query(p->right,Mid(p)+1,b);
	}
}

