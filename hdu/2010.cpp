#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(m>n) swap(m,n);
        bool flag=false;
        for(int i=m;i<=n;i++)
        {
            int a=i%10;
            int b=(i/10)%10;
            int c=i/100;
            if(i==a*a*a+b*b*b+c*c*c)
            {
                if(flag)
                    cout<<" ";
                flag=true;
                cout<<i;
            }
        }
        if(!flag)
        {
            cout<<"no";
        }
        cout<<endl;
    }
    return 0;
}
