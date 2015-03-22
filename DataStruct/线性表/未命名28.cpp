#include<iostream>
#include<string.h>
using namespace std;
const int maxn=10000;
int a[maxn],b[maxn],c[maxn];
char ch[1010],*ch1;
int change(char *ch)
{
	int len=strlen(ch);
	int x=0,h=1;
	if(ch[0]!='-')
	{
		for(int i=len-1;i>=0;i--)
		{
			x+=(ch[i]-'0')*h;
			h*=10;
		}
	}
	else
	{
		for(int i=len-1;i>=1;i--)
		{
			x+=(ch[i]-'0')*h;
			h*=10;
		}
		x=-x;
	}
	return x;
}
int main()
{
	while(gets(ch))
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		ch1=strtok(ch," ");
		int k=0;
		while(ch1!=NULL)
		{
			c[k++]=change(ch1);
			ch1=strtok(NULL," ");		
		}
		for(int i=0;i<k;i++)
		{

			a[c[i+1]+200]=c[i];
			i++;
		}
		gets(ch);
		ch1=strtok(ch," ");
		k=0;
		while(ch1!=NULL)
		{
			c[k++]=change(ch1);
			ch1=strtok(NULL," ");		
		}
		for(int i=0;i<k;i++)
		{
			b[c[i+1]+200]=c[i];
			i++;
		}
		for(int i=maxn;i>=0;i--)
		{
			a[i]+=b[i];
			if(a[i]!=0)
			{
				cout<<a[i]<<' '<<i-200<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}
