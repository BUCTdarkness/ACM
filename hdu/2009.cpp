#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    double n,m;
    while(cin>>n>>m)
    {
        double s,v;
        s=0;
        v=n;
        for(int i=1;i<=m;i++)
        {
            s+=v;
            v=sqrt(v);
        }
        printf("%.2f\n",s);
    }
    return 0;
}
