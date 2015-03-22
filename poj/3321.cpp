#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX=220000;
int c[MAX];
vector<vector<int> > g(MAX/2);
int lowbit[MAX];
bool has[MAX];
int beg[MAX],end[MAX];
int cnt=0;
void dfs(int v){
	beg[v]=++cnt;
	for(int i=0;i<g[v].size();i++) dfs(g[v][i]);
	end[v]=++cnt;
}
int query(int p){
	int sum=0;
	while(p>0){
		sum+=c[p];
		p-=lowbit[p];
	}
	return sum;
}
void add(int p,int v){
	while(p<=cnt){
		c[p]+=v;
		p+=lowbit[p];
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a].push_back(b);
		}
		cnt=0;
		dfs(1);
		for(int i=1;i<=cnt;i++) lowbit[i]=i&(i^(i-1));
		for(int i=1;i<=cnt;i++) c[i]=i-(i-lowbit[i]);
		for(int i=1;i<=n;i++) has[i]=true;
		int q;
		scanf("%d",&q);
		char cmd[10];
		for(int i=0;i<q;i++){
			int a;
			scanf("%s%d",cmd,&a);
			if(cmd[0]=='C'){
				if(has[a]){
					add(beg[a],-1);
					add(end[a],-1);
					has[a]=0;
				}
				else{
					add(beg[a],1);
					add(end[a],1);
					has[a]=1;
				}
			}
            else{
                int t1=query(end[a]);
                int t2=query(beg[a]-1);
                printf("%d\n",(t1-t2)/2);
            }
		}
	}
	return 0;
}
