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
bool cmp(double a,double b){
    return a>b;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        double A[100],sum=0;
        for(int i=0;i<N;i++){
            scanf("%lf",&A[i]);
        }
        sort(A,A+N,cmp);
        for(int i=0;i<N;i++){
            sum+=(pow(0.95,i)*A[i]);
        }
        printf("%.10lf\n",sum);
    }
    return 0;
}
