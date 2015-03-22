#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m;
	char ch[102][22];
	while(cin>>m)
	{
		memset(ch,'\0',sizeof(ch));
		for(int i=1;i<=m;i++)
		{
			cin>>ch[i];
			int p=i;
			int k=1;
			for(int count=0;count<4;count++)
			{
				cout<<k<<"="<<ch[p];
				p--;
				k++;
				if(p<=0)
				{
					break;
				}
				if(count!=3) cout<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
