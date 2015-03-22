#include<iostream>
#include<string.h>
using namespace std;
int c[100005],x,y;
int main()
{
	int T;
	cin>>T;
	
		while(T--)
		{
			int N,D;
			cin>>N>>D;
			c[0]=0;
			for(int i=1;i<N;i++)
			{
				cin>>x>>y;
				c[y]=c[x]+1;	
			}
			int sum=0;
			for(int i=0;i<N;i++)
			{
				if(c[i]>D)
					sum++;
			}
			cout<<sum<<endl;
		}
	return 0;
}
