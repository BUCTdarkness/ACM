#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX=100010;
int a[MAX];
void input(int n)
{
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}
int main()
{
    int t;
    while(cin>>t)
    {
        for(int k=1;k<=t;k++)
        {
            memset(a,0,sizeof(a));
            int sum;
            int n,s=1,e=1,x=1,y=1;
            cin>>n;
            input(n);
            int maxsum=a[1];
            sum=a[1];
            for(int i=2;i<=n;i++)
            {
                if(sum+a[i]>=a[i])
                {
                    sum+=a[i];
                    e=i;
                }
                else
                {
                    sum=a[i];
                    s=i;
                    e=i;
                }
                if(sum>maxsum)
                {
                    x=s;
                    y=e;
                    maxsum=sum;
                }
            }
            cout<<"Case "<<k<<":"<<endl;
            cout<<maxsum<<" "<<x<<" "<<y<<endl;
            if(k!=t)
                cout<<endl;
        }
    }
    return 0;
}

