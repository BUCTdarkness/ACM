#include<iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n&&m&&n)
	{
		int left,right,count;//×óÓÒ±ß½ç 
		count=2;
		for(left=right=m;2*right+1<=n;)
		{
			count*=2;
			left=2*left;
			right=2*right+1;
		}
		left*=2;
		if(left<=n)
		{
			count+=n-left+1;
		}
		cout<<count-1<<endl;
	}
	return 0;
}
