#include<iostream>
#include<stack>
using namespace std;
stack<char> s;
int main()
{
	char ch[150];
	while(cin>>ch&&ch[0]!='0')
	{
		bool flag=true;
		for(int pp=0;pp<=1;pp++){
			for(int qq=0;qq<=1;qq++){
				for(int rr=0;rr<=1;rr++){
					for(int ss=0;ss<=1;ss++){
						for(int tt=0;tt<=1;tt++)
						{
									for(int i=strlen(ch)-1;i>=0;i--)
									{
										if(ch[i]=='p')
											s.push(pp);
										if(ch[i]=='q')
											s.push(qq);
										if(ch[i]=='r')
											s.push(rr);
										if(ch[i]=='s')
											s.push(ss);
										if(ch[i]=='t')
											s.push(tt);   
										if(ch[i]=='N')
										{
											int x=s.top();
											s.pop();
											s.push(!x);
										}
										if(ch[i]=='K')
										{
											int x=s.top();
											s.pop();
											int y=s.top();
											s.pop();
											s.push(x&&y);
										}
										if(ch[i]=='A')
										{
											int x=s.top();
											s.pop();
											int y=s.top();
											s.pop();
											s.push(x||y);
										}
										if(ch[i]=='C')
										{
											int x=s.top();
											s.pop();
											int y=s.top();
											s.pop();
											s.push((!x)||y);
										}
										if(ch[i]=='E')
										{
											int x=s.top();
											s.pop();
											int y=s.top();
											s.pop();
											s.push(x==y);
										}
										
									}
									int ans=s.top();
									s.pop();
									if(!ans)
									{
										flag=false;
										break;
									}
						}
						if(!flag)
							break;
					}
					if(!flag)
						break;
				}
				if(!flag)
					break;
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"tautology"<<endl;
		else
			cout<<"not"<<endl;	
	}
	return 0;
}