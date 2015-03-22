#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX=100010;
int sum[MAX];
int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=N;i++)
        {
            int x;
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
        }
        bool flag=true;
        for(int i=N;i>=0&&flag;i--)
        {
            for(int j=0;j+i<=N;j++)
            {
                if((sum[j+i]-sum[j])%M==0)
                {
                    cout<<i<<endl;
                    flag=false;
                    break;
                }
            }
        }
    }
    return 0;
}

