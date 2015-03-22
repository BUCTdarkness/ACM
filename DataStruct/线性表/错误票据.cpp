#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const int maxn=110;
ll a[maxn],b[maxn]; 
char ch[maxn];
int main()
{
	int n;
	while(cin>>n)
	{
		int k=0;
		getchar();
		while(n--)
		{
			
			gets(ch);
			char *c;
			c=strtok(ch," ");
			while(c!=NULL)
			{
				a[k++]=atoi(c);
				c=strtok(NULL," ");
			}
		}
		sort(a,a+k);
/*
		for(int i=0;i<k;i++)
			cout<<a[i]<<endl;*/
		int x,y;
		for(int i=0;i<k-1;i++)
		{
			if(a[i]==a[i+1])
			{
				y=a[i];
			}
			else if(a[i]+1!=a[i+1])
			{
				x=a[i]+1;
			}
		} 
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
