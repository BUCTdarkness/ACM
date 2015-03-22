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
ll f[MAX];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        CLR(f);
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=m;j>=x;j--){
                f[j]=max(f[j],f[j-x]+y);
            }
        }
        cout<<f[m]<<endl;
    }
    return 0;
}
