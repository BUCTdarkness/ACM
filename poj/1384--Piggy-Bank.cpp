#include<iostream>
#include<string.h>
using namespace std;
#define maxn 5000000
int w[10005],p[10005],fa[10005];
int main()
{
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			int e,f,n;
			while(cin>>e>>f)
			{
				int ww=f-e;
				cin>>n;
				for(int i=0;i<n;i++)
				{
					cin>>p[i]>>w[i];
				}
				for(int i=1;i<=ww;i++)
				{
					fa[i]=maxn;
				}
				for(int i=0;i<n;i++)
				{
					for(int j=w[i];j<=ww;j++)
					{
						if(fa[j]>fa[j-w[i]]+p[i])
							fa[j]=fa[j-w[i]]+p[i];
					}
				}
				if(fa[ww]!=maxn)
				{
					cout<<"The minimum amount of money in the piggy-bank is "<<fa[ww]<<"."<<endl;
				}
				else
				{
					cout<<"This is impossible."<<endl;
				}
			}
		}
	}
	return 0;
}