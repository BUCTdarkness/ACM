#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
int main(){
    int k,p;
    while(cin>>k>>p){
        if(k/(p-1)&1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

