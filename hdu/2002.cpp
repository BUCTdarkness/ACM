#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const double PI=3.1415927;
int main()
{
    double r;
    while(cin>>r)
    {
        double v=(4*PI*r*r*r)/3;
        printf("%.3f\n",v);
    }
    return 0;
}

