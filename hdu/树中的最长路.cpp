#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=100010;
vector<int> g[MAX];
int vis[MAX],res=0; 
int dfs(int id){
	int sz=g[id].size(),l1=0,l2=0;
	for(int i=0;i<sz;i++){
		int v=g[id][i];
		if(vis[v]) continue;
		vis[v]=1;
		int l=dfs(v)+1;
		if(l>l1){l2=l1;l1=l;}
		else if(l>l2){l2=l;}
	}
	res= max(res,l1+l2);
	return l1;
}
int main(){
	int n;
	scanf("%d",&n);
	CLR(vis);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	res=0;vis[1]=1;
	dfs(1);
	cout<<res<<endl;
	return 0;
}
