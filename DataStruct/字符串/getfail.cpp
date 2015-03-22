#include<iostream>
#include<string.h>
using namespace std;
void getFail(char *p,int *f)
{
	int m=strlen(p);
	f[0]=-1;
	f[1]=0;
	for(int i=1;i<m;i++)
	{
		int j=f[i];
		while(j&&p[i]!=p[j])
			j=f[j];
		f[i+1]=p[i]==p[j]?j+1:0;
	}
}
int main()
{
	char p[110];
	int f[110];
	while(cin>>p)
	{
		getFail(p,f);
		for(int i=0;i<strlen(p);i++)
		{
			if(i!=0)
				cout<<f[i]<<" ";
			else
				cout<<f[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}