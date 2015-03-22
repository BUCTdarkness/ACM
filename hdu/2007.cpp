#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    __int64 m,n;
    while(cin>>m>>n)
    {
        __int64 s1=0;
        __int64 s2=0;
        if(m>n) swap(m,n);
        for(__int64 i=m;i<=n;i++)
        {
            if(i&1)
            {
                s1+=i*i*i;
            }
            else
            {
                s2+=i*i;
            }
        }
        cout<<s2<<" "<<s1<<endl;
    }
    return 0;
}
