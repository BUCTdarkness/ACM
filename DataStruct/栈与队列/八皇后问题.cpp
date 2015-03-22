#include<iostream>
using namespace std;
int ans[92][8],num,n,b,i,j,h[8],m;
void queen(int i)
{
	int j,k;
	if(i==m)
	{
		for(j=0;j<m;j++)
		{
			ans[num][j]=h[j]+1;
		}
		num++;
		return;
	}
	for(j=0;j<m;j++)
	{
		for(k=0;k<i;k++)
		{
			if(j==h[k]||abs(k-h[j])==abs(h[k]-j))
			{
				break;
			}
		}
		if(k==i)
		{
			h[i]=j;
			queen(i+1);
		}
	}
}
int main()
{
	num=0;
	cin>>m;
	queen(0);
	for(int i=0;i<num;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<ans[i][j];
			if(j!=m-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}