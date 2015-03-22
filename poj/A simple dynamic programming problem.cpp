#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MAXN 100100
using namespace std;
int A[MAXN],St[MAXN],Num[MAXN];
int main(){
    int T,kase=0,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        bool flag=0;
        if(N==0){
            printf("Case #%d: %d\n",++kase,1);
            continue;
        }
        for(int i=0;i<N;i++){
            scanf("%d",&A[i]);
            if(A[i]<0)    flag=1;
        }
        if(A[0]==0 || A[0]>3)    flag=1;
        if(flag==0)
        {
            for(int i=1;i<N;i++){
                if(abs(A[i]-A[i-1])>3 || (A[i]==A[i-1] && A[i]!=1)){
                    flag=1;break;
                }
            }
        }
        if(flag==1){
            printf("Case #%d: %d\n",++kase,0);
            continue;
        }
        memset(St,0,sizeof(St));
        memset(Num,0,sizeof(Num));
        St[0]=0;Num[0]=1;
        for(int i=1;i<N;i++){
            if(A[i]==2 && A[i-1]==1){
                St[i]=St[i-1];
                Num[i]=Num[i-1]+1;
            }
            else if(A[i]==1 && A[i-1]==2){
                St[i]=St[i-1]+1;
                Num[i]=Num[i-1]+1;    
            }
            else{
                Num[i]=Num[i-1];
            }
        }
        if(A[N-1])    Num[N-1]*=2;
        printf("Case #%d: %d\n",++kase,Num[N-1]);
    }
    
}