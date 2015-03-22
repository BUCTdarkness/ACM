//³ßÈ¡·¨
#include<iostream>
#include<algorithm>
using namespace std;
__int64 n,x;
const int maxn=100001;
__int64 a[maxn];
__int64 res=100010;
void solve()
{
    __int64 s=0,t=0,sum=0;
    res=n+1;
    for(;;)
    {
        while(t<n&&sum<x)
        {
            sum+=a[t++];
        }
        if(sum<x)
            break;
        res=min(res,t-s);
        sum-=a[s++];
    }
    if(res>n)
    {
        res=0;
    }
    cout<<res<<endl;
}
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>x;
            for(int i=0;i<n;i++)
                cin>>a[i];
            solve();
        }
    }
    return 0;
}
