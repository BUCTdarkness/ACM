#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define MAXN 110
#define INF 0x3f3f3f3f
int n,low[MAXN],dfn[MAXN],stack[MAXN],head,instack[MAXN],belong[MAXN];
int in[MAXN],out[MAXN],index,cnt,map[MAXN][MAXN];
void init(){
	CLR(map);CLR(low);CLR(instack);memset(dfn,-1,sizeof(dfn));
	index=cnt=1;head=0;
	int temp;
	for(int i=1;i<=n;i++){
		while(scanf("%d",&temp)&&temp) map[i][temp]=1;
	}
}
void tarjan(int x){
	low[x]=dfn[x]=index++;
	stack[++head]=x;instack[x]=1;
	for(int i=1;i<=n;i++){
		if(!map[x][i]) continue;
		if(dfn[i]==-1){
			tarjan(i);
			low[x]=min(low[x],low[i]);
		}
		else if(instack[i]) {
			low[x]=min(low[x],dfn[i]);
		}
 	}
 	if(low[x]==dfn[x]){
 		int tmp;
 		for(;;){
 			tmp=stack[head--];
 			belong[tmp]=cnt;
 			instack[tmp]=0;
 			if(tmp==x) break;
 		}
 		cnt++;
 	}
}
void solve(){
	while(~scanf("%d",&n)){
		init();
		for(int i=1;i<=n;i++){
			if(dfn[i]==-1) tarjan(i);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(map[i][j]&&belong[i]!=belong[j]){
					out[belong[i]]++;
					in[belong[j]]++;
				}
			}
		}
		int t1=0,t2=0;
		for(int i=1;i<cnt;i++){
			if(in[i]==0) t1++;
			if(out[i]==0) t2++;
 		}
 		if(cnt==2) printf("1\n0\n");
 		else printf("%d\n%d\n",t1,max(t1,t2));
	}
}
int main(){
	solve();
	return 0;
}


