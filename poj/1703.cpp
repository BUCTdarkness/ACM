//一道带权并查集。。orz
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
const int MAX=100005;
int r[MAX],p[MAX];
int find_set(int x){
    if(x==p[x]) return x;
    int y=p[x];
    p[x]=find_set(y);
    r[x]=(r[x]+r[y])%2;
    return p[x];
}
void union_set(int x,int y){
    int x1=find_set(x),y1=find_set(y);
    if(x1!=y1){
        p[y1]=x1;
        r[y1]=(2-1+r[x]+2-r[y])%2;
    }
}
int main(){
    int t;
    while(cin>>t){
        while(t--){
            int n,m;
            scanf("%d%d",&n,&m);
            for(int i=0;i<=n;i++){
                p[i]=i;r[i]=0;
            }
            while(m--){
                int x,y;
                char c[10];
                scanf("%s%d%d",c,&x,&y);
                if(c[0]=='D') union_set(x,y);
                else{
                    int u=find_set(x),v=find_set(y);
                    if(u==v){
                        int tmp=(2-r[x]+r[y])%2;
                        if(tmp==0) printf("In the same gang.\n");
                        else printf("In different gangs.\n");
                    }
                    else printf("Not sure yet.\n");
                }
            }
        }
    }
    return 0;
}
