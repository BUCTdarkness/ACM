#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=50005;
struct point
{
    int x,y,id;
    bool operator < (point a) const
    {
        return x<a.x;
    }
};
multiset<point> t;
point p;
int num[maxn];
int main()
{
    int n,m=0;
    while(cin>>n)
    {
        point temp;
        memset(num,-1,sizeof(num));
        int a;
        for(a=0;a<n;a++)
        {
            scanf("%d%d",&p.x,&p.y);
            p.id=a;
            t.insert(p);
        }
        multiset<point>::iterator i;
        a=1;
        while(!t.empty())
        {
            temp.x=t.begin()->y;
            i=t.upper_bound(temp);
            while(i!=t.end())
            {
                temp.x=i->y;
                num[i->id]=a;
                t.erase(i);
                i=t.upper_bound(temp);
            }
            num[t.begin()->id]=a++;
            t.erase(t.begin());
        }
        cout<<a-1<<endl;
        for(int i=0;i<n;i++)
            printf("%d\n",num[i]);
    }
    return 0;
}
