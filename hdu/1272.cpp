#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=100010;
int p[MAX];
bool vis[MAX];
bool flag=true;
int find_set(int v){return p[v]==v?v:p[v]=find_set(p[v]);}
void union_set(int a,int b){
    int x=find_set(a),y=find_set(b);
    if(x!=y){
        p[x]=y;
    }
    else{
        flag=false;
    }
}
int main(){
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        flag=true;
        if(a==-1&&b==-1) break;
        if(a==0&&b==0){
            printf("Yes\n");
            continue;
        }
        for(int i=0;i<MAX;i++){
            vis[i]=0;p[i]=i;
        }
        vis[a]=1;vis[b]=1;
        union_set(a,b);
        while(~scanf("%d%d",&a,&b)){
            if(a==0&&b==0) break;
            vis[a]=1;vis[b]=1;
            union_set(a,b);
        }
        int cnt=0;
        for(int i=1;i<MAX;i++){
            if(vis[i]&&p[i]==i) cnt++;
            if(cnt>=2){
                flag=false;break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
