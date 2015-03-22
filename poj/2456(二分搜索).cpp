#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX=100010;
int N,M;
int x[MAX];
bool C(int d)
{
	int last=0;
	for(int i=1;i<M;i++)
	{
		int crt=last+1;
		while(crt<N&&x[crt]-x[last]<d)
		{
			crt++;
		}
		if(crt==N)
			return false;
		last=crt;
	}
	return true;
}
int main(void)
{
	
	return 0;
}

