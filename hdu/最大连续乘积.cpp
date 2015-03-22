#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100010;
long long arr[MAXN],ma[MAXN],mi[MAXN];
int main()
{
    int n;
    long long ans;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ma[0]=mi[0]=ans=arr[0];
        for(int i=1;i<n;i++)
        {
            ma[i]=max(arr[i],max(ma[i-1]*arr[i],mi[i-1]*arr[i]));
            mi[i]=min(arr[i],min(ma[i-1]*arr[i],mi[i-1]*arr[i]));
            ans=max(ma[i],ans);
        }
        if(ans>0)
        {
            cout<<ans<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
    }
    return 0;
}

