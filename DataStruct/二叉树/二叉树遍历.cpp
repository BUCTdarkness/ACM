#include<iostream>
#include<string>
using namespace std;
int find (const string &str,char c)
{
	for(int i=0;i<str.size();i++)
	{
		if(c==str[i])
			return i;
	}
	return -1;
} 
void PreMid(string pre,string mid)
{
	if(pre.size()==0)
	{
		return ;
	}
	if(pre.size()==1)
	{
		cout<<pre[0];
		return ;
	}
	int k=find(mid,pre[0]);
	PreMid(pre.substr(1,k),mid.substr(0,k));
	PreMid(pre.substr(k+1,pre.size()-1),mid.substr(k+1,mid.size()-1));
	cout<<pre[0];
}
int main()
{
	string pre,mid;
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			cin>>pre>>mid;
			PreMid(pre,mid);
			cout<<endl;
		}
	}
	return 0;
}


