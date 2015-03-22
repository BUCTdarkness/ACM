#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 110
#define MAXM 55
using namespace std;
int dp[MAXN][MAXM];
int A[MAXN],score[MAXM][MAXM];
int main(){
    int T,M,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        memset(score,0,sizeof(score));
        memset(A,0,sizeof(A));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=M;i++)
            for(int j=1;j<=M;j++)
                scanf("%d",&score[i][j]);
        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);
        for(int i=2;i<=N;i++){
            for(int j=1;j<=M;j++){
                if(A[i]>0 && A[i]!=j)    continue;
                for(int k=1;k<=M;k++){
                    if(A[i]>0){
                        if(A[i-1]>0){
                            if(A[i-1]!=k)
                                continue;
                            dp[i][j]=dp[i-1][k]+score[k][j];
                            continue;
                        }
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+score[k][j]);
                        continue;
                    }
                    if(A[i-1]>0){
                        if(A[i-1]!=k)
                            continue;
                        dp[i][j]=max(dp[i][j],dp[i-1][k]+score[k][j]);
                        continue;
                    }
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+score[k][j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=M;i++)
            ans=max(ans,dp[N][i]);
        printf("%d\n",ans);
    }
}


