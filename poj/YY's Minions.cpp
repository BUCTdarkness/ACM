#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int cnt[55][55],leave[55][55];
char mp[55][55];
int dir[8][2]={1, 0, 0, 1, 0, -1, -1, 0, 1, 1, -1, -1, 1, -1, -1, 1};
int N,M,F,K;
int main(){
    int T;
    while(~scanf("%d",&T)){
        while(T--){
            scanf("%d%d%d%d",&N,&M,&F,&K);
            CLR(cnt);CLR(leave);
            for(int i=0;i<N;i++) scanf("%s",mp[i]);
            while(K--){
                int u,v,z;
                scanf("%d%d%d",&z,&u,&v);
                leave[u-1][v-1]=z;
            }
            for(int f=1;f<=F;f++){
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        for(int k=0;k<8;k++){
                            int dx=i+dir[k][1],dy=j+dir[k][0];
                            if(dx<0||dx>=N||dy<0||dy>=M) continue;
                            if(mp[dx][dy]=='1') cnt[i][j]++;
                        }
                    }
                }
                for(int i=0;i<N;i++){
                    for(int j=0;j<M;j++){
                        if(cnt[i][j]==3&&mp[i][j]=='0') mp[i][j]='1';
                        else if((cnt[i][j]<2||cnt[i][j]>3)&&mp[i][j]=='1') mp[i][j]='0';
                        if(leave[i][j]==f) mp[i][j]='X';
                        cnt[i][j]=0;
                    }
                }
            }
            for(int i=0;i<N;i++){
                printf("%s\n",mp[i]);
            }
        }
    }
    return 0;
}
