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
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            if(a%b)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;
            }
        }
    }
    return 0;
}
