#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdlib>
using namespace std;
struct Dis{
    int from,to;
    double v;
};
struct Point{
    int x,y;
}po[510];
double dist[1010];
priority_queue<Dis> q;
int fa[510],k=0;
bool operator < (const Dis &a,const Dis &b) {return a.v>b.v;}
inline double count(int x1,int x2,int y1,int y2){return sqrt( double( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) ) );}
inline int find_set(int a){return fa[a]==a?a:fa[a]=find_set(fa[a]);}
inline void union_set(int a,int b,double v){
    a=find_set(a);b=find_set(b);
    if(a==b) return;
    fa[b]=a;
    dist[k++]=v;
}
int main(){
    int t;
    while(cin>>t){
        while(t--){
            memset(dist,0,sizeof(dist));
            int s,p;
            scanf("%d%d",&s,&p);
            for(int i=0;i<p;i++) fa[i]=i;
            for(int i=0;i<p;i++) scanf("%d%d",&po[i].x,&po[i].y);
            Dis tmp;
            for(int i=0;i<p-1;i++)
                for(int j=i+1;j<p;j++){
                    tmp.from=i;tmp.to=j;
                    tmp.v=count(po[i].x,po[j].x,po[i].y,po[j].y);
                    q.push(tmp);
                }
            k=0;
            while(!q.empty()){
                tmp=q.top();q.pop();
                union_set(tmp.from,tmp.to,tmp.v);
            }
            sort(dist,dist+k);
            printf("%.2f\n",dist[k-s]);
        }
    }
    return 0;
}



