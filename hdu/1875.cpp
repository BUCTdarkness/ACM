#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=10010;
int p[MAX];
int n,m;
int cnt=0;
int find_set(int v){
    return p[v]==v?v:p[v]=find_set(p[v]);
}
void kruscal(){
    for(int i=0;i<cnt;i++){

    }
}
int main(){
    return 0;
}
