#include<iostream>
#include<string>
using namespace std;
int find(const string &str,char c)
{
	for(int i=0;i<str.size();i++)
		if(c==str[i])
			return i;
	return -1;
}
void PreMid(const string &pre,const string &mid)
{
	if(pre.size()==0)
	{
		return;
	}
/*
	if(pre.size()==1)
	{
		cout<<pre[0];
		return;
	}*/
	int k=find(mid,pre[0]);
	PreMid(pre.substr(1,k),mid.substr(0,k));//��ԭ������ 
	PreMid(pre.substr(k+1,pre.size()-k-1),mid.substr(k+1,mid.size()-k-1));//��ԭ������ 
	cout<<pre[0]; //������ڵ� 
}
int main()
{
	string pre,mid;
	while(cin>>pre>>mid)
	{
		PreMid(pre,mid);
		cout<<endl;
	}
	return 0;
}

