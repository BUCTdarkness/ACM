#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char s[10],ans[10],pre[1000][10];
int vis[10];
int len,p;
void dfs(int count)
{
	if(count==len)
	{
		int flag=1;
		for(int k=0;k<p;k++)
		{
			if(strcmp(ans,pre[k])==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			cout<<ans<<endl;
			strcpy(pre[p],ans);
			p++;
		}
		return;
	}
	for(int i=0;i<len;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ans[count]=s[i];
			dfs(count+1);
			vis[i]=0;
		}
	}
}
int main()
{
	while(gets(s))
	{
		memset(vis,0,sizeof(vis));
		memset(ans,'\0',sizeof(ans));
		len=strlen(s);
		p=0;
		dfs(0);
		cout<<endl;
	}
	return 0;
}
