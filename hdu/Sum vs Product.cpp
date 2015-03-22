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
using namespace std;
#define CLR(A,B) memset(A,B,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
#define long long ll
#define MP(A,B) make_pair(A,B)
int N;
long long cnt;
int dfs(int now,long long sum,long long mul,int pre){
    if(now==N){
        cnt++;
        return 1;
    }
    for(int i=pre;i<2000;i++){
        int ts=sum+i,tm=mul*i;
        int ms=ts+N-now-1,mm=tm;
        if(ms==mm){cnt++;continue;}
        if(ms<mm) return 0;
        dfs(now+1,ts,tm,i);
    }
}
int main(){
    int F[550];
    for(int i=2;i<=500;i++){
        N=i;cnt=0;
        dfs(0,0,1,2);
        F[i]=cnt;
    }
    while(~scanf("%d",&N)) printf("%d\n",F[N]);
	return 0;
}
