#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int ans[92][9],num,h[9];
void queen(int cur)
{
	if(cur==8)
	{
		for(int j=0;j<8;j++)
		{
			ans[num][j]=h[j]+1;
		}
		num++;
		return;
	}
	int k,j;
	for(k=0;k<8;k++)
	{
		for(j=0;j<cur;j++)
		{
			if(k==h[j]||abs(k-cur)==abs(h[j]-j))
			{
				break;
			}
		}
		if(j==cur)
		{
			h[cur]=k;
			queen(cur+1);
		}
	}
}
int main()
{
	int n;
	num=0;
	queen(0);
	while(cin>>n)
	{
		while(n--)
		{
			int b;
			cin>>b;
			for(int i=0;i<8;i++)
			{
				cout<<ans[b-1][i];
			}
			cout<<endl;
		}
	}
	return 0;
}