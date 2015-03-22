#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
class Solution {
private:
	string stmp;
	string init(string s)
	{
		string ret="$";
		for(int i=0;i<s.size();i++)
		{
			ret+="#"+s.substr(i,1);
		}
		ret+="#";
		return ret;
	}
	void Manacher(int len,string str,int *p)
	{
		int mx=0;
		int id;
		p[0]=0;
		for(int i=1;i<len;i++)
		{
			
			p[i]=1;
			if(mx>i)
			{
				p[i]=min(p[2*id-i],mx-i);
			}
			while(str[i-p[i]]==str[i+p[i]]) p[i]++;
			if(i+p[i]>mx)
			{
				id=i;
				mx=i+p[i];
			}
		}
	}
public:
    string longestPalindrome(string s) 
    {
        string str=init(s);
        int *p=new int[str.size()];
        Manacher(str.size(),str,p);
        int ans=0,index=0;
        for(int i=1;i<str.size();i++)
        {
        	if(p[i]>ans)
        	{
        		ans=p[i];
        		index=i;
        	}
        }
        delete []p;
        return s.substr((index-ans)/2,ans-1);
    }
};
int main(){
	int n;
	while(cin>>n){
		Solution s;
		string ret;
		for(int i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			ret=s.longestPalindrome(tmp);
			cout<<ret.size()<<endl;
		}
	}
	return 0;
}