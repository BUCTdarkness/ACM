#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    long long T,m,n,kase=0;
    cin>>T;
    while(T--)
    {
        long long maxt=0;
        cin>>n;
        long long x;
        long long sum=0;
        bool flag=0;
        m=2;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&x);
            sum+=x;
            maxt=max(x,maxt);
            if(x!=0)
                flag=1;
        }
        long long ans=max(maxt,(sum-1)/m+1);
        if(flag==0)    ans=0;
        cout<<"Case #"<<++kase<<": "<<ans<<endl;
    }
}