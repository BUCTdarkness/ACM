#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        cout<<lcm(a,b)<<endl;
    }
    return 0;
}



