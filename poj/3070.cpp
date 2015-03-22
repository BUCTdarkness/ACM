#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int v[15000];
int main(){
    v[0]=0;v[1]=1;
    for(int i=2;i<15000;++i){
        v[i]=v[i-1]+v[i-2];
        v[i]%=10000;
    }
    for(int n;~scanf("%d",&n)&&n!=-1;){
        cout<<v[n%15000]<<endl;
    }
    return 0;
}
