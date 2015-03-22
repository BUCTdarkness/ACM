#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
class Register
{
	public:
	int id;
	int time;
	int preiod;
	bool operator<(Register b) const
	{
		if(time==b.time)
		{
			return id>b.id;
		}
		return time>b.time;
	}
};
int main()
{
	priority_queue<Register> re;
	string cmd;
	int id,preiod,count;
	while(true)
	{
		cin>>cmd;
		if(cmd.compare("#")==0)
			break;
		cin>>id>>preiod;
		Register r;
		r.id=id;
		r.preiod=preiod;
		r.time=preiod;
		re.push(r);
	}
	cin>>count;
	while(count--)
	{
		Register tmp=re.top();
		cout<<tmp.id<<endl;
		tmp.time+=tmp.preiod;
		re.pop();
		re.push(tmp);
	}
	return 0;
}
