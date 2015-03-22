#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int N;
	while(cin>>N)
	{
		while(N--)
		{
			int M;
			cin>>M;
			for(int i=1;i<=3*M;i++)
			{
				for(int j=1;j<=M;j++)
				{
					cout<<"ACM";
				}
				cout<<endl;
			}
		}
	}
	return 0;
}