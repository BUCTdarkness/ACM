#include<iostream>
#include<cstring>
#define MAX_LEN 500
using namespace std;
struct HaffmanTree
{
	int weight;
	int parent;
	int lchild;
	int rchild;
};
HaffmanTree t[MAX_LEN];
int n,m;
void initialize()
{
	for(int i=1;i<=n;i++)
	{
		cin>>t[i].weight;
		t[i].parent=-1;
		t[i].lchild=-1;
		t[i].rchild=-1;
	}
	m=n+n-1;
	for(int i=n+1;i<=m;i++)
	{
		t[i].parent=-1;
		t[i].lchild=-1;
		t[i].rchild=-1;
	}
}
void createTree()
{
	for(int i=n+1;i<=m;i++)
	{
		int min1=1<<30;
		int min2=1<<30;
		int pos1,pos2;
		for(int j=1;j<i;j++)
		{
			if(t[j].parent==-1)
			{
				if(t[j].weight<min1)
				{
					pos2=pos1;
					min2=min1;
					pos1=j;
					min1=t[j].weight;
				}
				else if(t[j].weight<min2)
				{
					pos2=j;
					min2=t[j].weight;
				}
			}
		}
		if(pos1>pos2)
		{
			int temp=pos1;
			pos1=pos2;
			pos2=temp;
		}
		t[i].lchild=pos1;
		t[i].rchild=pos2;
		t[i].weight=t[pos1].weight+t[pos2].weight;
		t[pos1].parent=t[pos2].parent=i;
	}
}
void makecode1()
{
	char cd[n];
	int c=m;
	int cdlen=0;
	char hc[n+1][n+1];
	for(int i=1;i<=m;i++)
		t[i].weight=0;
	while(c!=-1)
	{
		if(t[c].weight==0)
		{
			t[c].weight=1;
			if(t[c].lchild!=-1)
			{
				c=t[c].lchild;
				cd[cdlen++]='0';
			}
			else if(t[c].rchild==-1)
			{
				cd[cdlen]='\0';
				strcpy(hc[c],cd);
			}
		}
		else if(t[c].weight==1)
		{
			t[c].weight=2;
			if(t[c].rchild!=-1)
			{
				c=t[c].rchild;
				cd[cdlen++]='1';
			}
		}
		else
		{
			t[c].weight=0;
			c=t[c].parent;
			--cdlen;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<hc[i]<<endl;
}
void makecode2()
{
	char cd[n];
	cd[n-1]='\0';
	for(int i=1;i<=n;i++)
	{
		int start=n-1;
		for(int c=i,f=t[i].parent;f!=-1;c=f,f=t[f].parent)
		{
			if(t[f].lchild==c)
			{
				cd[--start]='0';
			}
			else 
				cd[--start]='1';
		}
		for(int k=start;k<n-1;k++)
			cout<<cd[k];
		cout<<endl;
	}
}
int main()
{
	while(cin>>n)
	{
		memset(t,0,sizeof(t));
		initialize();
		createTree();
		makecode1();
	}
	return 0;
}
