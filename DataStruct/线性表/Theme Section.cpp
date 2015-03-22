#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1000005];
int d[2][1000005];
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>s;
			int len=strlen(s);
			memset(d,0,sizeof(d));
			int l1,l2,l3;
			int a,ans=0;
			for(l1=1;l1<=len-2;l1++)
			for(l2=l1+1;len-l2>=1;l2++)
			{
				memset(d,0,sizeof(d));
				int a1,a2,a3;
				for(int i=1;i<=l1;i++)
				{
					for(int j=l1+1;j<=l2;j++)
					{
						if(s[i-1]==s[j-1])
						{
							d[i&1][j]=d[(i-1)&1][j-1]+1;
						}
						else
						{
							d[i&1][j]=d[(i-1)&1][j]>d[i&1][j-1]?d[(i-1)&1][j]:d[i&1][j-1];
						}
					}
				} 
				a1=d[l1&1][l2];
				memset(d,0,sizeof(d));
					for(int i=1;i<=l1;i++)
					{
						for(int j=l2+1;j<=len;j++)
						{
							if(s[i-1]==s[j-1])
							{
								d[i&1][j]=d[(i-1)&1][j-1]+1;
							}
							else
							{
								d[i&1][j]=d[(i-1)&1][j]>d[i&1][j-1]?d[(i-1)&1][j]:d[i&1][j-1];
							}
						}
					}
					a2=d[l1&1][len];
					memset(d,0,sizeof(d));
					for(int i=l1+1;i<=l2;i++)
					{
						for(int j=l2+1;j<=len;j++)
						{
							if(s[i-1]==s[j-1])
							{
								d[i&1][j]=d[(i-1)&1][j-1]+1;
							}
							else
							{
								d[i&1][j]=d[(i-1)&1][j]>d[i&1][j-1]?d[(i-1)&1][j]:d[i&1][j-1];
							}
						}
					}
					a3=d[(l2)&1][len];
					a=min(a1,a2);
					a=min(a,a3);
					ans=max(ans,a);			
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 