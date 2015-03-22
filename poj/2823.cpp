//这题在poj里得用C++交
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=1000005;
int n,m;
int a[MAX],q[MAX];
void minq(){
    int tail=0,head=1;
    for(int i=1;i<=n;i++){
        while(head<=tail&&a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        if(i>=m){
            while(q[head]<i-m+1) head++;//判断是否过时。
            printf("%d ",a[q[head]]);
        }
    }
    printf("\n");
}
void maxq(){
    int tail=0,head=1;
    for(int i=1;i<=n;i++){
        while(head<=tail&&a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        if(i>=m){
            while(q[head]<i-m+1) head++;//判断是否过时。
            printf("%d ",a[q[head]]);
        }
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    minq();maxq();
    return 0;
}
