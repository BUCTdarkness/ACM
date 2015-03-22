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
vector<int> grayCode(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> res;
    int num = 1<<n;
    int i = 0;
    while(i<num)
        res.push_back((i>>1)^(i++));
    return res;
}
int getcc(int tmp){
	int ans=0;
	while(tmp){
		if(tmp&1) ans++;
		tmp>>=1;
	}
	return ans;
}
bool cmp(int a,int b){
	int x1=getcc(a),x2=getcc(b);
	return x1<x2;
}
void Print(int N,int num){
    vector<int>ans;
    while(num){
        ans.push_back(num&1);
        num>>=1;
    }
    for(int i=0;i<N-ans.size();i++) printf("0");
    for(int i=ans.size()-1;i>=0;i--) printf("%d",ans[i]);
    puts("");
}
int main(){
	int n;
//	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(~scanf("%d",&n)){
		vector<int> g=grayCode(n);
		int ma=-1;
		sort(g.begin(),g.end(),cmp);
		int len=g.size();
		for(int i=0;i<len;i++)
            Print(n,g[i]);
	}
	return 0;
}
