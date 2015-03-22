#include<iostream>
using namespace std;
int f[1000010];
struct Edge
{
	int u,v,c;
}edge[200010];
int F[200010];
int find(int x)
{
	if(F[x]==-1)
		return x;
	return F[x]=find(F[x]);
}
bool cmp1(Edge a,Edge b)
{
	return a.c<b.c;
}
bool cmp2(Edge a,Edge b)
{
	return a.c>b.c;
}
int main()
{
	int tot=1;
	f[0]=1;
	f[1]=2;
	while(f[tot]<=1000010)
	{
		f[tot+1]=f[tot]+f[tot-1];
		tot++;
	}
	int T;
	int iCase=0;
	int n,m;
	scanf("%d",&T);
	while(T--)
	{
		iCase++;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].c);
		}
		sort(edge,edge+m,cmp1);
		memset(F,-1,sizeof(F));
		int cnt=0;
		for(int i=0;i<m;i++)
		{
			int t1=find(edge[i].u);
			int t2=find(edge[i].v);
			if(t1!=t2)
			{
				F[t1]=t2;
				if(edge[i].c==1)
					cnt++;
			}
		}
		int Low=cnt;
		memset(F,-1,sizeof(F));
		sort(edge,edge+m,cmp2);
		cnt=0;
		for(int i=0;i<m;i++)
		{
			int t1=find(edge[i].u);
			int t2=find(edge[i].v);
			if(t1!=t2)
			{
				F[t1]=t2;
				if(edge[i].c==1)
					cnt++;
			}
		}
		int High=cnt;
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(find(i)!=find(1))
			{
				flag=false;
				break;
			}
		}
		if(!flag)
		{
			printf("Case #%d: No\n",iCase);
			continue;
		}
		bool ff=false;
		for(int i=0;i<=tot;i++)
		{
			if(f[i]>=Low&&f[i]<=High)
			{
				ff=true;
			}
		}
		if(ff)
			printf("Case #%d: Yes\n",iCase);
		else
			printf("Case #%d: No\n",iCase);
	}
	return 0;
}






















