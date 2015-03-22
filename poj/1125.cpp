#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int INF=30;//1<<30ณฌมห
int f[105][105];
int n;
void floyed(){
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

        int index=-1,ret=INF;
        for(int i=1;i<=n;i++){
            int maxlen=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                maxlen=max(maxlen,f[i][j]);
            }
            if(maxlen<ret){
                ret=maxlen;
                index=i;
            }
        }
        if(ret>=INF) cout<<"disjoint"<<endl;
        else cout<<index<<" "<<ret<<endl;
}
int main(){
    while(~scanf("%d",&n)&&n){
        for(int i=0;i<100;i++)
            for(int j=0;j<100;j++) f[i][j]=INF;
        for(int i=1;i<=n;i++){
            int m;scanf("%d",&m);
            for(int j=1;j<=m;j++){
                int u,v;
                scanf("%d%d",&u,&v);
                f[i][u]=v;
            }
        }
        floyed();
    }
    return 0;
}
