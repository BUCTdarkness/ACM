#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 50100
using namespace std;
int T,N,K;
int pos[MAXN],sum[MAXN],x[MAXN],First,Last;
double DL,DR,mass;
int PL,PR,need;
double ans,NowI;
double GetNext(){
    double ret=NowI;
    double pmass=mass;
    mass=(sum[Last+1]-sum[First]+0.0)/need;
    NowI+=-(pmass-pos[First])*(pmass-pos[First])+(mass-pos[Last+1])*(mass-pos[Last+1]);
    NowI+=(mass-pmass)*(mass-pmass)*(need-1);
    DL-=(pmass-pos[First]);
    Last++;First++;
    int t=PL-First+1;
    NowI+=2*DL*(mass-pmass);
    DL+=(mass-pmass)*t;
    PL++;
    while(PL<=N && pos[PL]<=mass){
        DL+=fabs(mass-pos[PL]);
        DR-=fabs(pmass-pos[PL]);
        NowI+=(mass-pos[PL])*(mass-pos[PL]);
        NowI-=(pmass-pos[PL])*(pmass-pos[PL]);
        NowI-=(mass-pmass)*(mass-pmass);
        PL++;
    }
    NowI+=2*(pmass-mass)*DR;
    DR+=(pos[Last]-mass);
    PL--;
    DR-=(mass-pmass)*(Last-(PL+1));
    return NowI;
}
int main(){
//    freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        for(int i=0;i<N;i++)
            scanf("%d",&pos[i]);
        sort(pos,pos+N);
        sum[0]=pos[0];
        for(int i=1;i<N;i++)
            sum[i]=sum[i-1]+pos[i];
        need=N-K;ans=0;PL=0;
        if(N==1 || need <2 ){
            puts("0.000000000000");
            continue;
        }
        double kkk=sum[need-1]*1.0/need;First=0;Last=need-1;
        DL=0;PL=0;DR=0;NowI=0;
        for(int i=0;i<need;i++){
            NowI+=(kkk-pos[i])*(kkk-pos[i]);
            if(pos[i]<=kkk){
                PL=i;
                DL+=(kkk-pos[i]);
            }
            else
                DR+=(pos[i]-kkk);
        }
        mass=kkk;
        ans=NowI;
        while(Last<N-1){
            GetNext();
            ans=min(ans,NowI);
        }
        printf("%.12lf\n",ans);
    }
}


