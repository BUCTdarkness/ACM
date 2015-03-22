//#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
#define MAXN 2000
#define MAXM 3000
#define LL long long
#define MOD 1000000007
#define CLR(A) memset(A,0,sizeof(A))
using namespace std;
LL dp[1<<20+5];
int main(){
	int t;
	while(cin>>t){
		while(t--){
			int n,k; LL l;
			scanf("%d%d%lld",&n,&k,&l);
			CLR(dp);
			int s=1<<k,y=l-k;
			l=k;
			dp[0]=1;
			while(n--){
				for(int i=s-1;i>=0;i--){
					if(dp[i]==0) continue;
					LL tmp=y*dp[i]%MOD;
					LL now=dp[i];
					for(int j=1;j<=l;j++){
						int next=i|(i<<j&(s-1)|(1<<(j-1)));
						dp[next]=(dp[next]+now);
						if(dp[next]>=MOD) dp[next]-=MOD;
					}
					dp[i]=dp[i]+tmp;
					if(dp[i]>=MOD) dp[i]-=MOD;
				}
			}
			LL ans=0;
			for(int i=0;i<s;i++){
				if(i&(1<<(k-1))){
					ans=ans+dp[i];
					if(ans>=MOD) ans-=MOD;
				}
			}
			printf("%lld\n",ans);	
		}
	}
	return 0;
}
