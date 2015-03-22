#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
const double pi=3.1415926535898;
const double e=exp((double)(1));
int main(){
    int t;
    while(cin>>t){
        while(t--){
            int n;
            cin>>n;
            int ret;
            ret=(int)(log10(sqrt(2.0*pi*n))+n*log10(n/e))+1);
            cout<<ret<<endl;
        }
    }
    return 0;
}


