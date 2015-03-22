#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=1500010;
char g[MAX];
int n,flag;
inline void check(ll ret){
    if(ret>100000){
        flag=true;
        while(n){if(getchar()=='\n') n--;}
    }
}
int main(){
    ll ret,cnt;
    while(~scanf("%d",&n)){
        flag=false;ret=1;cnt=1;
        getchar();
        while(n){
            char c=getchar();
            switch(c){
            case '{':
                cnt=1;
                while(c!='}'){
                    c=getchar();
                    if(c=='|') cnt++;
                    if(c=='\n') n--;
                }
                ret*=cnt;
                check(ret);
                break;
            case '$':
                cnt=1;
                c=getchar();
                while(c!='$'){
                    if(c==' ') cnt++;
                    else{
                        if(c=='\n') n--;
                        ret*=cnt;
                        cnt=1;
                        check(ret);
                        if(n==0) break;
                    }
                    c=getchar();
                }
                ret*=cnt;
                check(ret);
                break;
            case '\n': n--;break;
            default:;
            }
        }
        if(flag) cout<<"doge"<<endl;
        else cout<<ret<<endl;
    }
    return 0;
}


