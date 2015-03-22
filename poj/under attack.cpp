#include<iostream>
#include<cstring>
using namespace std;
int sum[15001];
int main()
{
    int n;
    while(cin>>n)
    {
        int l,r,w;
        memset(sum,0,sizeof(sum));
        while(cin>>l>>r>>w)
        {
            if(l==-1&&r==-1&&w==-1)
                break;
            sum[l]+=w;
            sum[r+1]-=w;
        }
        int ans=0;
        int min=0,max=0,maxv=0; 
        for(int i=1;i<=n;i++)
        {
            ans+=sum[i];
            sum[i]=ans;
            if(sum[i]==maxv)
            {
                max++;
            }
            if(sum[i]>maxv)
            {
                maxv=sum[i];
                min=i;
                max=i;
            }
        }
        cout<<min<<" "<<max<<endl; 
    }
    return 0;
}
