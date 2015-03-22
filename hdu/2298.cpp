#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define PI acos(-1.0)
#define G 9.8
#define exp 1e-12
using namespace std;
double X,Y,v,s;
double caculate(double x)
{
    double t;
    t=X/(v*(cos(x)));
    return v*sin(x)*t-0.5*G*t*t;
}
double triplediv()//Èý·Ö
{
    double mid1,mid2,l,r,h1,h2;
    l=0,r=0.5*PI;
    for(int i=0;i<100;i++)
    {
        mid1=(2*l+r)/3;
        mid2=(l+2*r)/3;
        h1=caculate(mid1);
        h2=caculate(mid2);
        h1>h2?r=mid2:l=mid1;
    }
    s=l;
    return caculate(l);
}
void doublediv(double y)
{
    double l,r,mid,h;
    l=0,r=s;
    for(int i=0;i<100;i++)
    {
        mid=(l+r)/2;
        h=caculate(mid);
        h>Y?r=mid:l=mid;
    }
    printf("%.6lf\n",l);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>X>>Y>>v;
        double y=triplediv();
        if(y<Y)
            cout<<"-1"<<endl;
        else
            doublediv(y);
    }
    return 0;
}

