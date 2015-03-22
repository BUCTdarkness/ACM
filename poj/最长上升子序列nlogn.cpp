#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_LEN=40005;
int a[MAX_LEN],b[MAX_LEN];
int bsearch(int len,int val)
{
    int low=0,high=len;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(val>b[mid])
        {
            low=mid+1;
        }
        else if(val<b[mid])
        {
            high=mid-1;
        }
        else
        {
            return low;
        }
    }
    return low;
}
int LIS(int n)
{
    b[0]=-1;
    b[1]=a[0];
    int len=1;
    for(int i=1;i<n;i++)
    {
        int j=bsearch(len,a[i]);
        b[j]=a[i];
        if(j>len)
        {
            len=j;
        }
    }
    return len;
}
int main(void)
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int n;
            cin>>n;
            for(int i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            cout<<LIS(n)<<endl;
        }
    }
    return 0;
}


