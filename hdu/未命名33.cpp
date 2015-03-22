#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
int main(){
	int n;
	while(cin>>n){
		int t=1,s=0;
		while(n){
			s+=t*(n+1)>>1;
			t<<=1;
			n>>=1;
		}
		cout<<s<<endl;
	}
	return 0;
}