#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
char ch[10010];
int f[10010];
int main()
{
	int t;
	f[2]=2;
	f[3]=3;
	while(cin>>t)
	{
		int k=1;
		while(t--)
		{
			cin>>ch;
			int len=strlen(ch);
			int s=1;
			int n=0;
			for(int i=0;i<len;i++)
			{
//				cout<<"s="<<s<<endl;
//				getch();
//				cout<<"n="<<n<<endl;
				int flag=0;
				s=s%10007;
				if(ch[i]=='h'&&ch[i+1]=='e')
				{
					i++;
					n++;
					flag=1;
				}
				if(flag==0||i==len-1)
				{
					if(n>=2)
					{
						if(n==2)
						{
							s*=2;
							n=0;
							continue;
						}
						if(n==3)
						{
							s*=3;
							n=0;
							continue;
						}
						for(int i=4;i<=n;i++)
						{
							f[i]=f[i-1]+f[i-2];
						}
						s*=f[n];
						n=0;
					}
					n=0;
				}
			}
			cout<<"Case "<<k<<": ";
			cout<<s%10007<<endl;
			k++;	
		}
	}
	return 0;
}