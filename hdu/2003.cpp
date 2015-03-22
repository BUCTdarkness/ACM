#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    double x;
    while(cin>>x)
    {
        x=abs(x);
        printf("%.2f\n",x);
    }
    return 0;
}
