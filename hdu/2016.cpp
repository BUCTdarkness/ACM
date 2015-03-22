#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=105;
int main()
{
    int a[MAX];
    int n;
    while(cin>>n&&n)
    {
        int m=1<<30;
        int p=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<m)
            {
                m=a[i];
                p=i;
            }
        }
        int t=a[p];
        a[p]=a[0];
        a[0]=t;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
