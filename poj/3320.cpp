#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000010;
int p;
int a[maxn];
void solve()
{
    set<int> all;
    for(int i=0;i<p;i++)
    {
        all.insert(a[i]);
    }
    int n=all.size();
    int s=0,t=0,num=0;
    map<int,int> cc;
    int res=p;
    for(;;)
    {
        while(t<p&&num<n)
        {
            if(cc[a[t++]]++==0)
                num++;
        }
        if(num<n)
            break;
        res=min(res,t-s);
        if(--cc[a[s++]]==0)
        {
            num--;
        }
    }
    cout<<res<<endl;
}
int main()
{
    while(cin>>p)
    {
        for(int i=0;i<p;i++)
            scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
