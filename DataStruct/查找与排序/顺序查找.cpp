#include<iostream>
#include<cstring>
using namespace std;
int find(int arr[],int n,int x)
{
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==x)
            return i;
    }
    return -1;
}
int main()
{
    int n,k,a[501];
    while(cin>>n>>k)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(k--)
        {
            int v;
            cin>>v;
            cout<<find(a,n,v)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
