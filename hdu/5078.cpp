#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAXN=1010;
ll x[MAXN],y[MAXN],t[MAXN];
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>t[i]>>x[i]>>y[i];
        double ans=0;
        for(int i=1;i<n;i++){
            double tmp=sqrt((x[i]-x[i-1])*(x[i]-x[i-1])+(y[i]-y[i-1])*(y[i]-y[i-1]))/(double)(t[i]-t[i-1]);
            ans=max(ans,tmp);
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}
