#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
char ch[1030];
char tree[3]={'B','I','F'};
int dfs(int start,int end)
{
	if(start==end)
	{
		cout<<tree[ch[start]-'0'];
		return ch[start]-'0';
	}
	int l=dfs(start,(start+end)/2);
	int r=dfs((start+end)/2+1,end);
	if(l==r)
	{
		cout<<tree[l];
		return l;
	}
	else
	{
		cout<<tree[2];
		return 2;
	}
}
int main()
{
	while(cin>>n>>ch)
	{
		dfs(0,strlen(ch)-1);
		cout<<endl;
	}	
	return 0;
}
 