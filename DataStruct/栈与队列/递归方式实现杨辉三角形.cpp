#include<iostream>
using namespace std;
int yanghui(int i,int j)
{
	int ans;
	if(j==1||j==i)
	{
		return 1;
	}
	else
	{
		ans=yanghui(i-1,j)+yanghui(i-1,j-1);
		return ans;
	}
}
void print(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<yanghui(i,j);
			if(j!=i)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	int n;
	while(cin>>n)
	{			print(n);
	}
	return 0;
} 
