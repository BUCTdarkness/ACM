#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
#define MAX 1005
#define CLR(A) memset(A,0,sizeof(A))
int N,K;
int a[MAX][10],b[10][MAX],mat[10][10],tmp[MAX][MAX],st[MAX][MAX];
void mul(){
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++) tmp[i][j]=st[i][j];
    }
    CLR(st);
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++) st[i][k]+=tmp[i][j]*tmp[j][k]%6;
            st[i][j]%=6;
        }
    }
}
void q_pow(){
    int t=N*N-1;
    while(t>0){
        if(t%2==1){
            for(int i=0;i<K;i++){
                for(int j=0;j<K;j++) tmp[i][j]=mat[i][j];
            }
            CLR(mat);
            for(int i=0;i<K;i++){
                for(int j=0;j<K;j++){
                    for(int k=0;k<K;k++) mat[i][k]+=tmp[i][j]*st[j][k]%6;
                    mat[i][j]%=6;
                }
            }
        }
        t/=2;mul();
    }
}
void create(){
    for(int i=0;i<N;i++)
        for(int j=0;j<K;j++) scanf("%d",&a[i][j]);
    for(int i=0;i<K;i++)
        for(int j=0;j<N;j++) scanf("%d",&b[i][j]);
    CLR(st);
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<K;k++) st[i][k]+=(a[i][j]*b[j][k])%6;
            st[i][j]%=6;
        }
    }
}
void solve(){
    CLR(mat);
    int ans=0,sum;
    for(int i=0;i<K;i++) mat[i][i]=1;
    q_pow();
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            tmp[i][j]=0;
            for(int k=0;k<K;k++) tmp[i][j]+=a[i][k]*mat[k][j];
            tmp[i][j]%=6;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            sum=0;
            for(int h=0;h<K;h++) sum+=tmp[i][h]*b[h][j];
            ans+=sum%6;
        }
    }
    printf("%d\n",ans);
}
main(){
    while(~scanf("%d%d",&N,&K)&&(N+K)){
        create();solve();
    }
    return 0;
}

