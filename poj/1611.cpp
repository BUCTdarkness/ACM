#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
const int MAX=30010;
int par[MAX];
int tot[MAX];
int getparent(int v){
	return par[v]==v?par[v]:par[v]=getparent(par[v]);
}
void merge(int a,int b){
	int p1=getparent(a),p2=getparent(b);
	if(p1!=p2){
		tot[p1]+=tot[p2];
		par[p2]=p1;
	}
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
		for(int i=0;i<n;i++){
			par[i]=i;
			tot[i]=1;
		}
		for(int i=0;i<m;i++){
			int a,b,k;
			scanf("%d%d",&k,&a);
			for(int j=1;j<k;j++){
				scanf("%d",&b);
				merge(a,b);
			}
		}
		printf("%d\n",tot[getparent(0)] );
	}
	return 0;
}
