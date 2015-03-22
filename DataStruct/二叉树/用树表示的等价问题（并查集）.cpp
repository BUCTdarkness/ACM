//my lovely 并查集算法 ,I am coming!!!!

#include<iostream>
#include<cstring>
#define MAX_LEN 105
using namespace std;
int p[MAX_LEN];
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			p[i]=i;
		int x,y;
		for(int i=0;i<k;i++)
		{
			cin>>x>>y;
			p[x]=y;
		}
		cin>>x>>y;
		if(find(x)==find(y))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl; 
		}
	}
	return 0;
} 
