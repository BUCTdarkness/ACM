#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int s=1;
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(x&1)
            {
                s*=x;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
