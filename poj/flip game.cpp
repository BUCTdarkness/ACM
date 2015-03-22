#include<iostream>
#define maxn 65536
using namespace std;
bool isvis[maxn*2];
int front ,rear;
int que[maxn];
int step[maxn];
int main()
{
	int id=0,tmp;
	char color;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cin>>color;
			id<<=1;
			if(color=='b')
				id+=1;
		}
	}
	if(id==0||id==65535)
	{
		cout<<0<<endl;
		return 0;
	}
	que[rear++]=id;
	isvis[id]=true;
	step[id]=0;
	while(front<rear)
	{
		tmp=que[front++];
		id=tmp;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				tmp=id;
				if(i==0)
				{
					tmp^=1<<(11-j);
				}
				else
				{
					if(i==3)
					{
						tmp^=1<<(7-j);
					}
					else
					{
						tmp^=1<<(11-4*i-j);
						tmp^=1<<(19-4*i-j);
					}
				}
				if(j==0)
				{
					tmp^=3<<(14-i*4);
				}
				else 
				{
					if(j==3)
					{
						tmp^=3<<(12-i*4);
					}
					else
					{
						tmp^=7<<(14-4*i-j);
					}
				}
				if(tmp==0||tmp==65535)
				{
					cout<<step[id]+1<<endl;
					return 0;
				}
				if(!isvis[tmp])
				{
					que[rear++]=tmp;
					isvis[tmp]=true;
					step[tmp]=step[id]+1;
				}
			}
	}
	cout<<"Impossible"<<endl;
	return 0;
}