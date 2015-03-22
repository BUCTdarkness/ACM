#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#define PI acos(-1.0)
#define exp 1e-9
using namespace std;
double solve(double r,double R,double h,double H)
{
    double u=h/H*(R-r)+r;
    return PI/3*(r*r+r*u+u*u)*h;
}
int main()
{
    int t;
    double r,R,H,V;
    cin>>t;
    while(t--)
    {
        cin>>r>>R>>H>>V;
        double lf=0.0;
        double rt=100.0;
        double mid;
        double v;
        while(rt-lf>exp)
        {
            mid=(rt+lf)/2;
            v=solve(r,R,mid,H);
            if(fabs(v-V)<=exp)
            {
                break;
            }
            else if(v>V)
            {
                rt=mid-exp;
            }
            else
            {
                lf=mid+exp;
            }
        }
        printf("%.6lf\n",mid);
    }
    return 0;
}
