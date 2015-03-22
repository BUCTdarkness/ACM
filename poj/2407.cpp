#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
inline int enlerfun(ll n){
	int tmp=n;
	for(int i=2;i<=n;i++){
		if(n%i==0){
			tmp-=tmp/i;
			while(n%i==0) n/=i;
		}
	}
	return tmp;
}
int main(){
	ll n;
	while(cin>>n&&n){
		cout<<enlerfun(n)<<endl;
	}
	return 0;
}
