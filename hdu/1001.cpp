#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    __int64 n;
    __int64 sum=0;
    while(cin>>n)
    {
        sum=n*(n+1)/2;
        cout<<sum<<endl<<endl;
    }
    return 0;
}

