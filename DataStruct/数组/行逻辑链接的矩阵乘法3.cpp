#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_LEN 12555
#define MAX_R 205
using namespace std;
typedef struct
{
	int x,y;
	int val;
}VALUE;
typedef struct
{
	int mu,nu,tu;
	VALUE data[MAX_LEN];
	int rpos[MAX_R];
} MAXTRIX;
void input(int r,int c,MAXTRIX &m)
{
	m.mu=r;
	m.nu=c;
	m.tu=0;
	int x;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			cin>>x;
			if(x)
			{
				m.data[m.tu].x=i;
				m.data[m.tu].y=j;
				m.data[m.tu].val=x;
				m.tu++;
			}
		}
	int num[200];
	memset(num,0,sizeof(num));
	for(int i=0;i<m.tu;i++)
	{
		num[m.data[i].x]++;
	}
	m.rpos[1]=0;
	for(int row=2;row<=m.mu+1;row++)
	{
		m.rpos[row]=m.rpos[row-1]+num[row-1];
	}
}
void caculate(MAXTRIX &m,MAXTRIX &t,MAXTRIX &q)
{
	q.mu=m.mu;
	q.nu=t.nu;
	q.tu=0;
	int ctemp[205];
	for(int arow=1;arow<=m.mu;arow++)
	{
		memset(ctemp,0,sizeof(ctemp));
		int mp;
		if(arow<m.mu)
			mp=m.rpos[arow+1];
		else
			mp=m.tu+1;
		for(int i=m.rpos[arow];i<mp;i++)
		{
			int brow=m.data[i].y;
			int tp;
			if(brow<t.mu)
				tp=t.rpos[brow+1];
			else
				tp=t.tu+1;
			for(int j=t.rpos[brow];j<tp;j++)
			{
				int col=t.data[j].y;
				ctemp[col]+=m.data[i].val*t.data[j].val;
			}
		}
		int p=0;
		for(int col=1;col<=q.nu;col++)
		{
			if(ctemp[col])
			{
				q.data[q.tu].val=ctemp[col];
				q.data[q.tu].x=arow;
				q.data[q.tu].y=col;
				q.tu++;
			}
		}
	}
}

void print(MAXTRIX ma)
{
	int k=0;
	for(int row=1;row<=ma.mu;row++)
	{
		for(int col=1;col<=ma.nu;col++)
		{
			int flag=0;
			if(ma.data[k].x==row&&ma.data[k].y==col)
			{
				flag=1;
				cout<<ma.data[k].val;
				k++;
			}
			if(flag==0)
			{
				cout<<"0";
			}
			cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int r,c;
	while(cin>>r>>c)
	{
		MAXTRIX m,t,q;
		input(r,c,m);
		cin>>r>>c;
		input(r,c,t);
		caculate(m,t,q);
		print(q);
	}
	return 0;
}
