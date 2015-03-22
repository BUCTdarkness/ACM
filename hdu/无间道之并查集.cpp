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
#define long long ll
#define MP(A,B) make_pair(A,B)
const int MAX=100010;
int N;
int p[MAX];
map<string,int> mp;
void init(){
    for(int i=0;i<MAX;i++)
        p[i]=i;
}
int find_set(int v){
    return p[v]==v?v:p[v]=find_set(p[v]);
}
void union_set(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a!=b){p[a]=b;}
}
bool query_set(int x,int y){
    int a=find_set(x),b=find_set(y);
    if(a==b) return true;
    else return false;
}
int main(){
    while(~scanf("%d",&N)){
        init();
        mp.clear();
        int cnt=0;
        while(N--){
            int ord;
            string a,b;
            cin>>ord>>a>>b;
            switch(ord){
            case 0:
                if(mp[a]==0) mp[a]=++cnt;
                if(mp[b]==0) mp[b]=++cnt;
                union_set(mp[a],mp[b]);
                break;
            case 1:
                if(mp[a]==0||mp[b]==0){
                    cout<<"no"<<endl;
                }
                else {
                    if(query_set(mp[a],mp[b])){
                        cout<<"yes"<<endl;
                    }
                    else{
                        cout<<"no"<<endl;
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    return 0;
}


