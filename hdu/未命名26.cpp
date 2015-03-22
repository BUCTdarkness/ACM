#include<iostream>  
using namespace std;  
long long x[1000005];
const int M=1000000007;
int main(void)  
{  
    int n;    
    x[0]=1;  
    for(int i=1;i<=1000004;i++)  
        x[i]=((x[i-1]%M+M)%M*((4*i-2))/(i+1))%M; 
	int t;
	while(cin>>t)
    for(int kase=1;kase<=t;kase++) 
    {  
    	scanf("%d",&n);
		printf("Case #%d:\n",kase);
		printf("%ld\n",x[n]);
    }
	return 0;  
}  