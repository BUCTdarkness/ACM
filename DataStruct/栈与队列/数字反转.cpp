#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int getLen(int x)
{
	int s=0;
	while(x)
	{
		x/=10;
		s++;
	}
	return s;
}
int change(int x)
{
	int len=getLen(x);
	int s=0,h=1;
	for(int i=1;i<len;i++)
	{
		h*=10;
	}
	while(x)
	{
		s+=x%10*h;
		h/=10;
		x/=10;
	}
	return s;
} 
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			int a,b;
			cin>>a>>b;
			int sum1,sum2;
			sum1=a+b;
			sum2=change(a)+change(b);
			if(sum1==change(sum2))
			{
				cout<<sum1<<endl;
			} 
			else
			{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
