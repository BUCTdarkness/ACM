#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
typedef __int64 ll;
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return r;
}
int main()
{
	ll x,y,m,n,l,p,t;
	ll a,b,c,d;
	cin>>x>>y>>m>>n>>l;
	bool flag=false;
	if(m==n)
	{
		flag=true;
	}
	else
	{
		a=n-m;
		b=l;
		d=x-y;
		c=gcd(a,b);
		if(d%c!=0)
			flag=true;
	}
	if(flag)
	{
		cout<<"Impossible"<<endl;
	}
	else
	{
		a/=c;
		b/=c;
		exgcd(a,b,t,p);
		d/=c;
		t*=d;
		t=t%b;
		if(t<b)
		{
			t+=b;
		}
		cout<<t%b<<endl;
	}
	return 0;
}

