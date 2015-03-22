#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double dis(double x1,double y1,double x2,double y2)
{
    double s=0;
    s=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return s;
}
int main()
{
    double x1,y1,x2,y2;
    while(cin>>x1>>y1>>x2>>y2)
    {
        printf("%.2f\n",dis(x1,y1,x2,y2));
    }
    return 0;
}
