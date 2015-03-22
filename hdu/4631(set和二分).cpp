#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define LL long long 
using namespace std;
const int MAXN=600000;
LL Ax,Bx,Cx,Ay,By,Cy,ans,n;
class Point
{
public:
	LL x,y;
	bool operator < (const Point &rhs) const 
	{
		return x<rhs.x;
	}
};
Point p[MAXN];
int main()
{
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			cin>>n>>Ax>>Bx>>Cx>>Ay>>By>>Cy;
			p[0].x=0;
			p[0].y=0;
			multiset<Point> S;
			S.clear();
			for(int i=1;i<=n;i++)
			{
				p[i].x=(p[i-1].x*Ax+Bx)%Cx;
				p[i].y=(p[i-1].y*Ay+By)%Cy;
			}
			LL mindis;
			mindis=((LL) 1<<62);
			S.insert(p[1]);
			ans=0;
			for(int i=2;i<=n;i++)
			{
				multiset<Point>::iterator pp=S.lower_bound(p[i]),iter;
				for(iter=pp;iter!=S.begin();)
				{
					iter--;
					Point t=*iter;
					LL a=t.x-p[i].x;
					a*=a;
					if(a>=mindis)
						break;
					LL b=t.y-p[i].y;
					b*=b;
					mindis=min(mindis,a+b);
				}
				for(;pp!=S.end();pp++)
				{
					Point t=*pp;
					LL a=t.x-p[i].x;
					a*=a;
					if(a>=mindis)
						break;
					LL b=t.y-p[i].y;
					b*=b;
					mindis=min(mindis,a+b);
				}
				S.insert(p[i]);
				ans+=mindis;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
