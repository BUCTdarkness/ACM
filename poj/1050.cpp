#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAX_LEN=110;
int mat[MAX_LEN][MAX_LEN];
int n;
int subMaxSum(int a[])
{
	int sum=-10000000,b=0;
	for(int i=0;i<n;i++)
	{
		if(b>0)
			b+=a[i];
		else
			b=a[i];
		sum=max(sum,b);
	}
	return sum;
}
int maxSum()
{
	int sum=0,ans=-10000000;
	for(int i=0;i<n;i++)
	{
		int b[MAX_LEN]={0};
		for(int j=i;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				b[k]+=mat[j][k];
			}
			sum=subMaxSum(b);
			ans=max(ans,sum);
		}
	} 
	return ans;
}
int main()
{
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				scanf("%d",&mat[i][j]);
			}
		cout<<maxSum()<<endl;
	}
	return 0;
}
