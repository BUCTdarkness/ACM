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
const int MAXN=10010;
const int MOD=20000;
string str;
bool vis[MOD];
unsigned int hasha(const char *url){
    unsigned int n=0;
    char *b=(char*) &n;
    for(int i=0;url[i];++i) b[i%4]^=url[i];
    return n%MOD;
}
int main(){
    while(cin>>str){
        int len=str.size();
        int ans=0;
        CLR(vis,0);
        for(int l=1;l<=len;l++){
            for(int i=0;i<len;i++){
                string tmp=str.substr(i,l);
                int id=hasha(tmp.c_str());
                if(!vis[id]){
                    vis[id]=1;int cnt=0;
                    for(int j=0;j<len;){
                        const char *p=strstr(str.c_str()+j,tmp.c_str());
                        if(p==NULL) j++;
                        else{
                            cnt++;
                            int t=p-str.c_str();
                            j=t+tmp.size();
                        }
                    }
                    if(cnt>=2) {ans++;}
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

