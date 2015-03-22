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
LL dpx[1010][1024][2];
LL dpa[1010][1024][2];
int a[MAXN];
inline void check(LL &t){while(t>=MOD) t-=MOD;}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		CLR(dpx);CLR(dpa);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<n;++i){//从前往后 
			dpx[i][a[i]][1]+=1;
			for(int j=0;j<1024;++j){
				dpx[i+1][j^a[i+1]][1]+=dpx[i][j][1];
				dpx[i+1][j^a[i+1]][1]+=dpx[i][j][0];
				dpx[i+1][j][0]+=dpx[i][j][1];
				dpx[i+1][j][0]+=dpx[i][j][0];
				check(dpx[i+1][j^a[i+1]][1]);
				check(dpx[i+1][j][0]);
			}
		}	
		for(int i=n;i>1;--i){//从后往前 
			dpa[i][a[i]][1]+=1;
			for(int j=0;j<1024;++j){
				dpa[i-1][j&a[i-1]][1]+=dpa[i][j][1];
				dpa[i-1][j&a[i-1]][1]+=dpa[i][j][0];
				dpa[i-1][j][0]+=dpa[i][j][1];
				dpa[i-1][j][0]+=dpa[i][j][0];
				check(dpa[i-1][j&a[i-1]][1]);
				check(dpa[i-1][j][0]);
			}
		}
		LL ret=0;
		for(int i=1;i<n;++i){
			for(int j=0;j<1024;++j){
				ret=(ret+dpx[i][j][1]*(dpa[i+1][j][0]+dpa[i+1][j][1]))%MOD;
			}
		}
		printf("%I64d\n",ret);
	}
	return 0;
}
