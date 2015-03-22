#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long  LL;
const int MAX = 120000;
struct Point 
{
    LL x,y;
};
inline LL det(LL x1, LL y1, LL x2, LL y2)
{return x1 * y2 - x2 * y1;}
int cmp(const void *a, const void *b)
{
    if((*(Point*)a).y - (*(Point*)b).y)
        return (*(Point*)a).x - (*(Point*)b).x;
    return (*(Point*)a).y - (*(Point*)b).y;
}
LL cross(Point a, Point b, Point c)
{return det(b.x -a.x, b.y - a.y, c.x - a.x, c.y - a.y);}
LL Graham(Point p[], Point res[], LL n, LL &top)
{
    LL len, i;
    top = 1;
    qsort(p, n, sizeof(Point),cmp);
    res[0] = p[0], res[1] = p[1];
    for(i = 2; i < n; ++ i)
    {
        while(top && cross(res[top], res[top - 1], p[i]) <= 0)
            -- top;
        res[++ top] = p[i];
    }
    len = top;
    res[++ top] = p[n - 2];
    for(i = n - 3; i >= 0; -- i)
    {
        while(top != len && cross(res[top], res[top - 1], p[i]) <= 0)
            -- top;
        res[++ top] = p[i];
    }
    return top;
}
Point p[MAX], res[MAX];
LL n, m;
int main()
{
    LL maxx, maxy;
    int t;
    while(cin>>t)
	    while(t--)
	    {
	        cin>>n;
	        for(int i = 0; i < n; ++ i)
	            scanf("%I64d%I64d", &p[i].x, &p[i].y);
	        p[n] = p[0];
	        Graham(p, res, n, m);
	        for(int i = maxx = maxy = 0; i < m; ++ i)
	        {
	            if(res[i].x > res[maxx].x) maxx = i;
	            if(res[i].y > res[maxy].y) maxy = i;
	        }
	        cout<<(maxx - maxy + n) % n + 1<<endl;
	    }
    return 0;
}
