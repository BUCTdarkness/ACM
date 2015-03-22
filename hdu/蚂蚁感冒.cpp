#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100;
int a[MAXN];
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int sum=0;
        if(a[0]>0)
        {
            bool flag=false;
            for(int i=1;i<n;i++)
            {
                if(a[i]<0&&-a[i]>a[0])
                {
                    flag=true;
                    sum++;
                }
            }
            for(int i=1;i<n&&flag;i++)
            {
                if(a[i]>0&&a[i]<a[0])
                {
                    sum++;
                }
            }
            sum++;
        }
        else
        {
            bool flag=false;
            for(int i=1;i<n;i++)
            {
                if(a[i]>0&&a[i]<-a[0])
                {
                    flag=true;
                    sum++;
                }
            }
            for(int i=1;i<n&&flag;i++)
            {
                if(a[i]<0&&a[i]<a[0])
                {
                    sum++;
                }
            }
            sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
