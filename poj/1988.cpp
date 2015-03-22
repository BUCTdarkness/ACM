#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#include <set>
using namespace std;
const int MAX=31000;
int parent[MAX];
int sum[MAX];
int under[MAX];
int getparent(int v){
	if(parent[v]==v) return v;
	int tmp=getparent(parent[v]);
	under[v]+=under[parent[v]];
	parent[v]=tmp;
	return parent[v];
}
void merge(int a,int b){
	int pa=getparent(a),pb=getparent(b);
	if(pa!=pb){
		parent[pb]=pa;
		under[pb]=sum[pa];
		sum[pa]+=sum[pb];
	}
}
void init(){
	for(int i=0;i<MAX;i++){
		under[i]=0;
		sum[i]=1;
		parent[i]=i;
	}
}
int main(){
	int p;
	while(scanf("%d",&p)!=EOF){
        init();
        for(int i=0;i<p;i++){
            char cmd[10];
            scanf("%s",cmd);
            int a,b;
            if(cmd[0]=='M'){
                scanf("%d%d",&a,&b);
                merge(b,a);
            }
            else{
                scanf("%d",&a);
                getparent(a);
                printf("%d\n",under[a] );
            }
        }
	}
	return 0;
}
