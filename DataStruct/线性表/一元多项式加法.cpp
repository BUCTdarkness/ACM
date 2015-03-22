#include<iostream>
#include<string.h>
using namespace std;
const int maxn=1010;
int a[maxn],b[maxn],c[maxn];
char ch[3010],*ch1;
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
	while(gets(ch)&&strlen(ch))
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

			a[c[i+1]]=c[i];
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
			b[c[i+1]]=c[i];
			i++;
		}
		int flag=0;
		for(int i=maxn;i>=0;i--)
		{
			a[i]+=b[i];
			if(a[i]!=0)
			{
				flag=1;
				cout<<a[i]<<' '<<i<<' ';
			}
		}
		if(flag==0) cout<<0;
		cout<<endl;
	}
	return 0;
}
