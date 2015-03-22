#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long ll;
inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll ex_gcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return a;
	}
	else{
		ll d=ex_gcd(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-(a/b)*y;
		return d;
	}
}
int main(){
	ll x,y,m,n,l;
	while(cin>>x>>y>>m>>n>>l){
		ll a=n-m,b=l,c=x-y;
		ll d=gcd(a,b);
		if(c%d){
			puts("Impossible");
			continue;
		}
		a/=d;b/=d;c/=d;
		ll p,q;
		ex_gcd(a,b,p,q);
		p*=c;
		ll t=p%b;
		while(t<0) t+=b;
		printf("%lld\n",t);
	}
	return 0;
}
