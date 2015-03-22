#include<stdio.h>
int main(int a,int n){
	for(;scanf("%d",&n),a=n&-n;) 
		printf("%d\n",n+a+(n^n+a)/a/4);
	return 0;
}
