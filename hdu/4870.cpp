#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
double [20][20],dp[20];
int main(){
    double p;
    while(cin>>p){
        dp[0]=1/p;dp[1]=1+(1-p)/p*(dp[0]+1);
        for(int i=2;i<=19;i++) dp[i]=1+(1-p)/p*(dp[i-2]+dp[i-1]+1);
        ans[0][0]=0;ans[1][0]=dp[0];ans[1][1]=ans[1][0]+dp[0];
        for(int i=1;i<=19;i++){
            ans[i+1][i]=ans[i][i]+dp[i];
            ans[i+1][i+1]=ans[i+1][i]+dp[i];
        }
        printf("%.6lf\n",ans[20][19]);
    }
    return 0;
}
