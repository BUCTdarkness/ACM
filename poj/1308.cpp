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
#define CLR(p) memset(p,0,sizeof(p))
const int MAX=110;
int p[MAX];
bool used[MAX];
inline int getparent(int a){
	return p[a]==a?a:p[a]=getparent(p[a]);
}
inline void init(){
	for(int i=0;i<MAX;i++) p[i]=i;
	memset(used,false,sizeof(used));
}
inline void merge(int x,int y){
    x=getparent(x);y=getparent(y);
    if(x==y) return;
    p[y]=x;
}
int main(){
	int u,v;
	int cas=0;
	while(scanf("%d%d",&u,&v)!=EOF){
		if(u==-1&&v==-1) break;
		if(u==0&&v==0) {
            printf("Case %d ",++cas);
            printf("is a tree.\n");
            continue;
		}
        init();
		used[u]=used[v]=true;
		int first=u;
		bool flag=true;
		if(u==v) flag=false;
		else merge(u,v);
		while(scanf("%d%d",&u,&v)!=EOF){
            if(u==0&&v==0) break;
            used[u]=used[v]=true;
			if(u!=v&&getparent(u)==getparent(v)) flag=false;
			merge(u,v);
		}
		printf("Case %d ",++cas);
		if(!flag){
			printf("is not a tree.\n");
			continue;
		}
		for(int i=0;i<MAX;i++){
			if(used[i]&&getparent(first)!=getparent(i)){
				flag=false;
				break;
			}
		}
		if(!flag){
			printf("is not a tree.\n");
		}
		else{
			printf("is a tree.\n");
		}
	}
	return 0;
}

