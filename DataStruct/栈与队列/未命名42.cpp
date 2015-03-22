#include<iostream>
#include<string.h>
using namespace std;
char ch[1010];
int main()
{
	while(cin>>ch)
	{
		int len=strlen(ch);
		int i=0;
		int j=len-1;
		while(ch[i]==ch[j])
		{
			if(j<=i)
				break;
			i++;
			j--;
			
		}
		if(j<=i)
		{
			cout<<"Yes!"<<endl;
		}
		else
		{
			cout<<"No!"<<endl;
		}
	}
	return 0;
}