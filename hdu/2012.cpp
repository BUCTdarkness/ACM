#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=3010;
bool isprime[MAX];
void init()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for(int i=2;i<=MAX;i++)
    {
        if(isprime[i])
        {
            for(int j=2*i;j<=MAX;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}
int f(int n)
{
    return n*n+n+41;
}
int main()
{
    int x,y;
    init();
    while(cin>>x>>y&&(x||y))
    {
        bool flag=false;
        for(int i=x;i<=y;i++)
        {
            if(!isprime[f(i)])
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Sorry"<<endl;
        }
        else
        {
            cout<<"OK"<<endl;
        }
    }
    return 0;
}
