#include<iostream>
using namespace std;
const int maxn=100000;
char ch[100000];
int num[100000];
int main()
{
	int T;
	while(cin>>T)
	{
		while(T--)
		{
			cin>>ch;
			int len=strlen(ch);
			for(int i=0;i<len;i++)
			{
				num[len-1-i]=ch[i]-'0';								//在这里只关心最后一位！若最后一位加上某个数，刚好可以，那么久加上，若要进位则重新来 
			}
			while(1)
			{
				int sum=0;
				for(int i=0;i<len;i++)
				{
					sum+=num[i];
					sum=sum%10;
				}
				if(sum%10==0)
				{
					int flag=0;
					for(int i=maxn;i>=0;i--)
					{
						if(num[i]&&flag==0)						if(num[i]&&flag==0)
						{
							flag=1;
						}
						if(flag) cout<<num[i];
					}
					cout<<endl;
					break;
				} 
				int c=10-sum;
				if(num[0]+c<10)
				{
					num[0]+=c;
				}
				else
				{
					num[0]+=c;
					for(int i=0;i<maxn;i++)
					{
						if(num[i]>=10)
						{
							num[i]%=10;
							num[i+1]+=1;
						}
					}
				}
			}
		}
	}
	return 0;
}