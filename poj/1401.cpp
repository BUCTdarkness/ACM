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
int main(){
    int n;
    while(cin>>n){
        while(n--){
            int x;
            cin>>x;
            int sum=0;
            while(x){
                sum+=x/5;
                x/=5;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}
