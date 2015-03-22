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
#define CLR(A) memset(A,0,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
double cal(double x,double y){
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double y;
        scanf("%lf",&y);
        double lower=0,upper=100;
        for(int i=0;i<100;i++){
            double u=(2*lower+upper)/3,v=(lower+2*upper)/3;
            if(cal(u,y)<cal(v,y)) upper=v;
            else lower=u;
        }
        printf("%.4lf\n",cal((lower+upper)/2,y));
    }
    return 0;
}
