#include<iostream>
#include<string.h>
#include<algorithm>
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
	int j,k;
	for(k=0;k<8;k++)
	{
		for(j=0;j<cur;j++)
		{
if(k==h[j]||abs(j-cur)==abs(h[j]-k))
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
int main(void)
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
