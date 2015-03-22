#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int A[110][110];
int main(){
    int T,m,n;
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(n==1 && m==1){
            cout<<1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                A[i][j]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(A[i][j]==1){
                    A[i-1][j]<<=1;
                    A[i+1][j]<<=1;
                    A[i][j-1]<<=1;
                    A[i][j+1]<<=1;
                }
            }
        long long sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(A[i][j]!=1){
                    sum+=A[i][j];
                }
            }
        cout<<sum<<endl;
    }
}
