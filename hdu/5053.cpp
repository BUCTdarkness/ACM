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
int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif
    int T,kase=0;
    scanf("%d",&T);
    while(T--){
        printf("Case #%d: ",++kase);
        long long A,B;
        scanf("%I64d%I64d",&A,&B);
        long long sum=0;
        long long sum1=(A-1)*(A)/2;
        sum1=sum1*sum1;
        long long sum2=(B)*(B+1)/2;
        sum2=sum2*sum2;
        cout<<sum2-sum1<<endl;
    }
    return 0;
}