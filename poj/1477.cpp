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
const int MAXN=1000;
int main(){
    int a[MAXN],sum;
    int n;
    int cas=0;
    while(~scanf("%d",&n)&&n){
        sum=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        int ans=0;
  //  cout<<sum<<endl;
        for(int i=0;i<n;i++){
            if(a[i]>sum/n){
                ans+=sum/n-a[i];
            }
        }
        printf("Set #%d\n",++cas);
        printf("The minimum number of moves is %d.\n",ans);
    }
    return 0;
}
