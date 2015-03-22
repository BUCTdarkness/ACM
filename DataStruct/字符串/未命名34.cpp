#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char s[10],ans[10];
int vis[10];
int len;
void dfs(int count)
{
	if(count==len)
	{
		cout<<ans<<endl;
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
	gets(s);
		memset(vis,0,sizeof(vis));
		memset(ans,'\0',sizeof(ans));
		len=strlen(s);
		dfs(0);
		cout<<endl;
	return 0;
}
