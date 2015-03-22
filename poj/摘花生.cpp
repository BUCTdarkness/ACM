#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
const int MAX=110;
int dp[MAX][MAX];
int v[MAX][MAX];
int main(){
    int t,r,c;
    while(~scanf("%d",&t)){
        while(t--){
            memset(dp,0,sizeof(dp));memset(v,0,sizeof(v));
            scanf("%d%d",&r,&c);
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++){
                    scanf("%d",&v[i][j]);
                }
            for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+v[i][j];
                }
            cout<<dp[r][c]<<endl;
        }
    }
    return 0;
}
