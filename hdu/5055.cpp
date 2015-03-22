#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
using namespace std;
#define lowbit(x) (x)&(-x)
#define CLR(A) memset(A,0,sizeof(A))
bool cmp(int a,int b){
    return a>b;
}
int a[200];
int n;
int main(){
    while(cin>>n){
        int v=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n,cmp);
        for(int i=n-1;i>=0;i--){
            if(a[i]%2==1){ v=i;break;}
        }
        if(v==-1){
            puts("-1");continue;
        }
        swap(a[v],a[n-1]);
        sort(a,a+(n-1),cmp);
        if(a[0]==0){puts("-1");continue;}
        for(int i=0;i<n;i++) cout<<a[i];
        cout<<endl;
    }
    return 0;
}
