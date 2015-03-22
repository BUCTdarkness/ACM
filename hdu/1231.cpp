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
int a[MAX];
int main(){
    int n;
    while(~scanf("%d",&n)&&n){
        bool flag=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]>=0) flag=1;
        }
        if(flag){
            int sum=a[0],tmp=a[0],beg=a[0],end=a[0];
            int ret=INT_MIN;
            for(int i=0;i<n;i++){
                sum+=a[i];
                if(ret<sum){
                    ret=sum;
                    beg=tmp;
                    end=a[i];
                }
                if(sum <0 ){
                    sum=0;
                    if(i!=n-1) tmp=a[i+1];
                }
            }
            printf("%d %d %d\n",ret,beg,end);
        }
        else{
            printf("0 %d %d\n",a[0],a[n-1]);
        }
    }
    return 0;
}

