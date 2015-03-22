#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        __int64 h=1;
        for(int i=1;i<=n-1;i++)
        {
            h=2*(h+1);
        }
        cout<<h<<endl;
    }
    return 0;
}
