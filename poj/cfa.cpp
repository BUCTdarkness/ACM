#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
    int a=0,b=0;
    for(int i=0;i<3;i++){
        int v;
        cin>>v;
        a+=v;
    }
    for(int i=0;i<3;i++){
        int v;
        cin>>v;
        b+=v;
    }
    int sum;
    cin>>sum;
    int n1=a/5,n2=b/10;
    if(a%5>0) n1++;
    if(b%10>0) n2++;
    if(n1+n2<=sum) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
//  //  cout<<a<<" "<<b<<" "<<n<<" "<<sum<<endl;
//    if(n==0||a%5!=0) n++;
//    sum-=n;
//    if(sum*10>=b){
//        cout<<"YES"<<endl;
//    }
//    else{
//        cout<<"NO"<<endl;
//    }
    return 0;
}

