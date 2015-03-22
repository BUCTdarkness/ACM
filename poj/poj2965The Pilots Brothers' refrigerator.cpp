#include<iostream>
using namespace std;
#define maxn 65536
int que[maxn];
bool isvis[maxn*2];
int step[maxn];
int front,rear;
struct xx
{
	int x,y;
};
struct xxx
{
	xx num[100];
	int len;
};
xxx ch[maxn];
int main()
{
	char x;
	int id=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			cin>>x;
			id<<=1;
			if(x=='+')
				id+=1;
		}
//	bitset<16>b(id);
//	cout<<b<<endl; 
	que[rear++]=id;
	isvis[id]=true;
	step[id]=0;
	ch[id].len=0;
	while(front<rear)
	{
		int tmp=que[front++];
		id=tmp;
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				tmp=id;
				if(i==0)
				{
					tmp^=273<<(3-j);
				}
				if(i==3)
				{
					tmp^=4368<<(3-j);
				}
				if(i==1)
				{
					tmp^=1<<(15-j);
					tmp^=17<<(3-j);
				}
				if(i==2)
				{
					tmp^=1<<(3-j);
					tmp^=4352<<(3-j);
				}
				tmp^=15<<(12-4*i);
//				bitset<16>b(tmp);
//				cout<<b<<endl;
//				getch();
				if(!isvis[tmp])
				{
					step[tmp]=step[id]+1;
					int k;
					for(k=0;k<ch[id].len;k++)
					{
						ch[tmp].num[k].x=ch[id].num[k].x;
						ch[tmp].num[k].y=ch[id].num[k].y;
					}
					ch[tmp].num[k].x=i;
					ch[tmp].num[k].y=j;
					ch[tmp].len=ch[id].len+1;
					que[rear++]=tmp;
					isvis[tmp]=true;
				}
				if(tmp==0)
				{
					cout<<step[id]+1<<endl;
					int k;
					for(k=0;k<ch[id].len;k++)
					{
						cout<<ch[id].num[k].x+1<<" "<<ch[id].num[k].y+1<<endl;
					}
					cout<<i+1<<" "<<j+1<<endl;
					return 0;
				}

			}
	}
	return 0;
}