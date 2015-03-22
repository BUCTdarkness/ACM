#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX_LEN=25050;
struct Interval
{
    int b,e;
}data[MAX_LEN];
int N,T;
bool cmp(Interval x,Interval y)
{
    if(x.b==y.b)
    {
        return x.e<y.e;
    }
    else
    {
        return x.b<y.b;
    }
}
int main()
{
    while(cin>>N>>T)
    {
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&data[i].b,&data[i].e);
        }
        sort(data,data+N,cmp);
        int right=0,top=0,start,ans=0;
        while(right<T)
        {
            start=right+1;
            for(int i=top;i<N;i++)
            {
                if(data[i].b<=start&&data[i].e>=start)
                {
                    right=max(right,data[i].e);
                }
                else if(data[i].b>start)
                {
                    top=i;
                    break;
                }
            }
            if(start>right)
                break;
            else
                ans++;
        }
        if(right>=T)
            cout<<ans<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
