#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=210;
int p[MAX];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        CLR(p);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(i==j) continue;
                if(p[i]==p[j]){cnt++;}
            }
            if(cnt==0) printf("BeiJu\n");
            else printf("%d\n",cnt);
        }
    }
    return 0;
}
