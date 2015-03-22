#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX=5001;
int n;
int dir[MAX];
int f[MAX];
int calc(int K)
{
    memset(f,0,sizeof(f));
    int res=0;
    int sum=0;
    for(int i=0;i+K<=n;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i+1>=K)
        {
            sum-=f[i+1-K];
        }
    }
    for(int i=n-K+1;i<n;i++)
    {
        if((dir[i]+sum)%2!=0)
        {
            return -1;
        }
        //sum+=f[i];
        if(i+1>=K)
        {
            sum-=f[i+1-K];
        }
    }
  //  cout<<"sss"<<endl;
    return res;
}
void solve()
{
    int M=n,K=1;
    for(int k=1;k<=n;k++)
    {
        int m=calc(k);
//        cout<<m<<endl;
        if(m>=0&&m<M)
        {
            M=m;
            K=k;
        }
    }
    cout<<K<<" "<<M<<endl;
}
int main()
{
    while(cin>>n)
    {
        char c,x;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            getchar();
            if(c=='B')
                dir[i]=1;
            else
                dir[i]=0;
        }
        //for(int i=0;i<n;i++) cout<<f[i]<<" ";
        solve();
    }
    return 0;
}

