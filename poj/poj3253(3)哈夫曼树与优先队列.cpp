#include<iostream>
#include<queue>
using namespace std;
class node 
{
public:
	int w;
	 bool operator<(node b) const
	{
		return w>b.w; 
	}
}tmp;
int main()
{
	int n;
    while(cin>>n)
	{
		int ans=0;
        priority_queue<node>q;
		for(int i=0;i<n;i++)
		{
			cin>>tmp.w;
			q.push(tmp);
		}
		while(q.size()>1)
		{
			node a=q.top();
			q.pop();
			node b=q.top();
			q.pop();
			a.w+=b.w;
			ans+=a.w;
			q.push(a);
		}
		cout<<ans<<endl;
	}
	return 0;
}

