#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=100010;
double num[MAX];
double len[MAX];
int main(){
    int T;
    while(~scanf("%d",&T)){
        while(T--){
            int n,cnt=0;
            CLR(num);CLR(len);
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                int v;scanf("%d",&v);
                num[cnt]=v;
                len[cnt]=1;
                while(cnt>=1){
                    if(num[cnt]*len[cnt-1]>num[cnt-1]*len[cnt]) break;
                    num[cnt-1]+=num[cnt];
                    len[cnt-1]+=len[cnt];
                    cnt--;
                }
                cnt++;
            }
            double ret=0.0;
            for(int i=0;i<cnt;i++){
                double x=num[i]/len[i];
                ret+=x*x*(len[i]-num[i])+(1-x)*(1-x)*num[i];
            }
            printf("%.6lf\n",ret);
        }
    }
    return 0;
}
