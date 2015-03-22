//多重背包问题
//感觉像是完全背包问题多了一个数量限制
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
const int MAX=110;
int a[MAX],c[MAX],used[100010];
bool f[100010];
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n+m){
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        CLR(f);f[0]=true;
        int ret=0;
        for(int i=0;i<n;i++){
            CLR(used);
            for(int j=a[i];j<=m;j++){
                if(!f[j]&&f[j-a[i]]&&used[j-a[i]]<c[i]){
                    used[j]=used[j-a[i]]+1;
                    f[j]=true;
                    ret++;
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}

