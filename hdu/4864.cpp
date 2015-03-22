#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
const int MAXN=100001;
struct Work{
    int x,y;
}w[MAXN];
struct Task{
    int x,y;
}t[MAXN];
inline int f(int x,int y){return 500*x+2*y;}
bool cmp1(Work a,Work b){
    if(a.x==b.x) return a.y<b.y;
    return a.x>b.x;
}
bool cmp2(Task a,Task b){return a.x>b.x;}
int n,m;
bool vis[MAX];
int find(int l,int u){
}
int main(){
    while(scanf("%d%d",&n,&m)){
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){scanf("%d%d",&w[i].x,&w[i].y);}
        for(int i=0;i<m;i++){scanf("%d%d",&t[i].x,&t[i].y);}
        sort(w,w+n,cmp1);sort(t,t+m,cmp2);
        int cnt=0;
        long long sum=0;
        int h=0;
        for(int i=0;i<m;i++){
            bool flag=false;
            for(int j=0;j<n;j++){
                if(w[j].x>=t[i].x&&w[j].y>=t[i].y){
                    flag=true;vis[j]=true;
                    cnt++;sum+=f(t[i].x,t[i].y);
                }
            }
            if(!flag) break;
        }
        printf("%d %ld\n",cnt,sum);
    }
    return 0;
}
