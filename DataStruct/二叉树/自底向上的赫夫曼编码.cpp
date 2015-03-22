#include<iostream>
#include<cstring>
#define MAX_LEN 500
using namespace std;
struct HaffmanTree
{
	int weight;
	int parent;
	int leftchild;
	int rightchild;
};
HaffmanTree t[MAX_LEN];
int main()
{
	int n;
	while(cin>>n)
	{
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++)
		{
			cin>>t[i].weight;
			t[i].parent=-1;
			t[i].leftchild=-1;
			t[i].rightchild=-1;
		}
		int m=n+n-1;
		for(int i=n+1;i<=m;i++)
		{
			t[i].parent=-1;
			t[i].leftchild=-1;
			t[i].rightchild=-1;
		}
		for(int i=n+1;i<=m;i++)
		{
			int min1=1<<30;
			int min2=1<<30;
			int pos1;
			int pos2;
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
			t[i].leftchild=pos1;
			t[i].rightchild=pos2;
			t[i].weight=t[pos1].weight+t[pos2].weight;
			t[pos1].parent=t[pos2].parent=i;
		}
		char cd[n];
		char hc[n][500];
		cd[n-1]='\0';
		for(int i=1;i<=n;i++)
		{
			int start=n-1;
			for(int c=i,f=t[i].parent;f!=-1;c=f,f=t[f].parent)
			{
				if(t[f].leftchild==c)
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
	return 0;
}

