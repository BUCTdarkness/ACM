#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int main(){
    int T;
    while(cin>>T){
        while(T--){
            int n,a[110];
            cin>>n;CLR(a);
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(j%i) continue;
                    a[j]=!a[j];
                }
            }
            int ret=0;
            for(int i=1;i<=n;i++){
                if(a[i]!=0) ret++;
            }
            cout<<ret<<endl;
        }
    }
    return 0;
}
