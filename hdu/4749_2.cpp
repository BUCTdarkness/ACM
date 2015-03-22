#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=120000;
int g1[26][MAX],g2[26][MAX];
int p[MAX],a[MAX],b[MAX];
int vis[MAX];
int n,m,t;
int ok(int x,int y){
    int c1=0,c2=0,c3=0;
    if(g1[a[x]][x-1]!=g1[a[y]][y-1]-g1[a[y]][y-x]) return 0;
    for(int i=1;i<a[x];i++) c1+=g1[i][x-1];
    for(int i=1;i<a[y];i++) c2+=g1[i][y-1];
    for(int i=1;i<a[y];i++) c3+=g1[i][y-x];
    if(c1!=c2-c3) return 0;
    return 1;
}
int judge(int x,int y){
    int c1=0,c2=0,c3=0;
    if(g1[a[x]][x-1]!=g2[b[y]][y-1]-g2[b[y]][y-x]) return 0;
    for(int i=1;i<a[x];i++) c1+=g1[i][x-1];
    for(int i=1;i<b[y];i++) c2+=g2[i][y-1];
    for(int i=1;i<b[y];i++) c3+=g2[i][y-x];
    if(c1!=c2-c3) return 0;
    return 1;
}
void get_next(){
    p[1]=0;
    int j=0;
    for(int i=2;i<=n;i++){
        while(j&&!ok(j+1,i)) j=p[j];
        if(ok(j+1,i)) j++;
        p[i]=j;
    }
}
void kmp(){
    int j=0;
    for(int i=1;i<=m;i++){
        while(j&&!judge(j+1,i)) j=p[j];
        if(judge(j+1,i)) j++;
        if(j==n){
            vis[i]=1;
            j=p[j];
        }
    }
}
int main(){
    while(~scanf("%d%d%d",&m,&n,&t)){
        CLR(g1);CLR(g2);CLR(vis);
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
            for(int j=1;j<=t;j++)
                g2[j][i]=g2[j][i-1];
            g2[b[i]][i]++;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            for(int j=1;j<=t;j++)
                g1[j][i]=g1[j][i-1];
            g1[a[i]][i]++;
        }
        get_next();kmp();
        int ans=0;
        int i=1;
        while(i<=m){
            if(vis[i]){
                ans++;i+=n;
            }
            else i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

