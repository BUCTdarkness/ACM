#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m)
    {
        while(m--)
        {
            double s=0;
            int h=1;
            cin>>n;
            for(double i=1;i<=n;i++)
            {
                s+=h*(double)(1/i);
                h=-h;
              //  cout<<"ss"<<endl;
            }
            printf("%.2f\n",s);
        }
    }
    return 0;
}
