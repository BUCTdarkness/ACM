#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef __int64 ll;
const int MOD=1000000007;
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
            ans=(ans*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return ans%MOD;
}
int solve(int x)
{
    ll ans;
    if(x==1)
        return 1;
    if(x==2)
        return 2;
    if(x==3)
        return 5;
    ans=((2*qpow(2,x-2))%MOD+((x-2)*qpow(2,x-3))%MOD)%MOD;
    return ans;
}
int main()
{
    int T;
    while(cin>>T)
    {
        while(T--)
        {
            int n,k;
            cin>>n>>k;
            if(k>n)
            {
                cout<<0<<endl;
                continue;
            }
            int x=n-(k-1);
            cout<<solve(x)<<endl;
        }
    }
    return 0;
}

