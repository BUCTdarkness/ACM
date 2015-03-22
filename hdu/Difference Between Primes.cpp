#include<iostream>
#include<cmath>
using namespace std;
int isprime(double n)
{
	if((int)n==2)
		return 1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if((int)n%i==0)
			return 0;
	}
	return 1;
}
int main()
{
	int t;
	while(cin>>t)
	{
		while(t--)
		{
			int m;
			int i=2;
			int flag=0;
			int sign=1;
			cin>>m;
			if(m==0)
			{
				cout<<"2 2"<<endl;
				continue;
			}
			else
			{
				if(m<0)
				{
					m=-m;
					sign=0;
				}
				
			}
			while(i<2000000)
			{
				if(isprime(i)&&isprime(m+i))
				{
					if(sign)
						cout<<m+i<<" "<<i<<endl;
					else
						cout<<i<<" "<<m+i<<endl;
					flag=1;
					break;
				}
				i++;
			}
			if(flag==0)
			{
				cout<<"FAIL"<<endl;
			}
		}
	}
	return 0;
}
