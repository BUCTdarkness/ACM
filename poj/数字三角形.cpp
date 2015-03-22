#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
const int MAXN=110;
int n;
int main(){
	int dp[MAXN][MAXN];
	while(cin>>n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++)
				cin>>dp[i][j];
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
			}
		}
		cout<<dp[1][1]<<endl;
	}
	return 0;
}
