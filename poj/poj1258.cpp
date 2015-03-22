#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100000;
struct Edge
{
    int u,v;
    int w;
}edge[MAXN];
int p[MAXN];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while(cin>>n)
    {
        __int64 ans=0;
        int m=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                __int64 x;
                scanf("%lld",&x);
                if(x)
                {
                    edge[m].u=i;
                    edge[m].v=j;
                    edge[m].w=x;
                    m++;
                }
            }
        sort(edge,edge+m,cmp);
        for(int i=0;i<=MAXN;i++)
        {
            p[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int x=find(edge[i].u);
            int y=find(edge[i].v);
            if(x!=y)#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100000;
struct Edge
{
    int u,v;
    int w;
}edge[MAXN];
int p[MAXN];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while(cin>>n)
    {
        __int64 ans=0;
        int m=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                __int64 x;
                scanf("%lld",&x);
                if(x)
                {
                    edge[m].u=i;
                    edge[m].v=j;
                    edge[m].w=x;
                    m++;
                }
            }
        sort(edge,edge+m,cmp);
        for(int i=0;i<=MAXN;i++)
        {
            p[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int x=find(edge[i].u);
            int y=find(edge[i].v);
            if(x!=y)
            {
                ans+=edge[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}



            {
                ans+=edge[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100000;
struct Edge
{
    int u,v;
    int w;
}edge[MAXN];
int p[MAXN];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
    int n;
    while(cin>>n)
    {
        __int64 ans=0;
        int m=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                __int64 x;
                scanf("%lld",&x);
                if(x)
                {
                    edge[m].u=i;
                    edge[m].v=j;
                    edge[m].w=x;
                    m++;
                }
            }
        sort(edge,edge+m,cmp);
        for(int i=0;i<=MAXN;i++)
        {
            p[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            int x=find(edge[i].u);
            int y=find(edge[i].v);
            if(x!=y)
            {
                ans+=edge[i].w;
                p[x]=y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


