#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    int a,b,c;
    while(cin>>n&&n)
    {
        a=b=c=0;
        for(int i=0;i<n;i++)
        {
            double x;
            scanf("%lf",&x);
            if(x<0) a++;
            if(x==0) b++;
            if(x>0) c++;
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}

