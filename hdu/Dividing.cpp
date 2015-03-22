#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAX=120010;
int f[MAX];
int m[7];
int V;
void ZeroOnePack(int v,int c)
{
    for(int i=V;i>=v;i--)
    {
        f[i]=max(f[i-v]+c,f[i]);
    }
}
void CompletePack(int v,int c)
{
    for(int i=v;i<=V;i++)
    {
        f[i]=max(f[i-v]+c,f[i]);
    }
}
void MutiPack(int v,int c,int n)
{
    if(n*v>=V)
    {
        CompletePack(v,c);
    }
    else
    {
        int k=1;
        while(k<n)
        {
            ZeroOnePack(k*v,k*c);
            n-=k;
            k*=2;
        }
        ZeroOnePack(n*v,n*c);
    }
}

int main()
{
    int sum,num=1;
    while(true)
    {
        sum=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&m[i]);
            sum+=i*m[i];
        }
        if(sum==0)
            break;
        if(sum%2)
        {
            printf("Collection #%d:\nCan't be divided.\n\n",num);
            num++;
            continue;
        }
        V=sum/2;
        memset(f,0,sizeof(f));
        for(int i=1;i<=6;i++)
        {
            MutiPack(i,i,m[i]);
        }

        if(f[V]==V)
            printf("Collection #%d:\nCan be divided.\n\n",num);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",num);
        num++;
    }
    return 0;
}
