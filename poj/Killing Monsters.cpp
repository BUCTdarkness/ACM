#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#define MAXN 100100
using namespace std;
long long damage[MAXN];
long long adddmg[MAXN];
int main(){
    int T,N,M;
    while(~scanf("%d",&T) && T){
        memset(damage,0,sizeof(damage));
        memset(adddmg,0,sizeof(adddmg));
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            damage[x]+=d;damage[y+1]-=d;
        }
        for(int i=2;i<=100000;i++)
            damage[i]=damage[i]+damage[i-1];
        adddmg[100000]=damage[100000];
        for(int i=99999;i>0;i--)
            adddmg[i]=damage[i]+adddmg[i+1];
        scanf("%d",&M);
        int cnt=0;
        for(int i=0;i<M;i++){
            long long hp;int pos;
            scanf("%I64d%d",&hp,&pos);
            if(adddmg[pos]<hp)
               cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
