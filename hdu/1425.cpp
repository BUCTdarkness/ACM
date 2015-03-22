#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAX=1000010;
bool h[MAX];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(h,0,sizeof(h));
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            h[x+500000]=true;
        }
        for(int i=1000000;i>0&&m>0;i--){
            if(h[i]){
                m--;
                m==0?printf("%d\n",i-500000):printf("%d ",i-500000);
            }
        }
    }
    return 0;
}



