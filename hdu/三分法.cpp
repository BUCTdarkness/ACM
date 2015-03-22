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
int cal(int v){
}
int solve(int b,int e){
    int lower=b,upper=e;
    for(int i=0;i<100;i++){
        int u=(2*lower+upper)/3,v=(lower+2*upper);
        if(cal(u)<cal(v)) upper=v;
        else lower=u;
    }
    return cal((lower+upper)/2);
}
int main(){

    return 0;
}


