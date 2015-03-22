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
const int MAXN=1100;
char ch1[MAXN],ch2[MAXN];
int dp[MAXN][MAXN];
int main(){
	while(cin>>ch1>>ch2){
		int len1=strlen(ch1),len2=strlen(ch2);
		for(int i=0;i<=len1;i++) dp[i][0]=0;
		for(int i=0;i<=len2;i++) dp[0][i]=0;
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(ch1[i-1]==ch2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
				else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
		cout<<dp[len1][len2]<<endl;
	}
	return 0;
}
