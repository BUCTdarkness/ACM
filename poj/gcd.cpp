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
inline gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int ex_gcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;y=0;return a;
	}
	else{
		int d=ex_gcd(b,a%b,x,y);
		int t=x;
		x=y;
		y=t-(a/b)*y;
		return d;
	}
}
bool init(){
	memset(prime,0,sizeof(prime));
	memset(isprime,1,sizeof(isprime));
	for(int i=2;i<=n;i++){
		if(isprime[i]) prime[num++]=i;
		for(int j=1;j<num&&i*prime[j]<=n;j++){
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0) break;
		}
	}
}
