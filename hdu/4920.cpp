#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
#define CLR(A)  memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=810;
short A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
inline short read(){
    char s=0,t;
    while(t=getchar(),t>47){s+=t-'0';}
    return s%3;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        getchar();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j]=read();
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                B[i][j]=read();
            }
        }
        CLR(C);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    C[i][k]+=A[i][j]*B[j][k];
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%d",C[i][0]%3);
            for(int j=1;j<n;j++){
                printf(" %d",C[i][j]%3);
            }
            printf("\n");
        }
    }
    return 0;
}

