#include<iostream>
#define MAX_LEN 12555
#define MAX_C 205
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
	int rpot[MAX_R];
	int cpot[MAX_C];
}MATRIX;
MATRIX m,t,q;
void FastTransposeSMatrix()
{
	int cpot[200];
	for(int i=1;i<=t.nu;i++)
	{
		cpot[i]=t.cpot[i];
	}
	for(int i=0;i<t.tu;i++)
	{
		int col=t.data[i].y;
		int pos=cpot[col];
		q.data[pos].x=t.data[i].y;
		q.data[pos].y=t.data[i].x;
		q.data[pos].val=t.data[i].val;
		cpot[col]++;
	}
	q.tu=t.tu;
	q.mu=t.nu;
	q.nu=t.mu;
	int num1[200];
	memset(num1,0,sizeof(num1));
	for(int i=0;i<q.tu;i++)
	{
		num1[q.data[i].x]++;
	}
	q.rpot[1]=0;
	for(int row=2;row<=q.mu+1;row++)
	{
		q.rpot[row]=q.rpot[row-1]+num1[row-1];
	}
}
void print(MATRIX ma)
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
void caculate()
{
	t.mu=m.mu;
	t.nu=q.mu;
	int h=0;
	memset(t.data,0,sizeof(t.data));
/*
	for(int row=1;row<=q.mu;row++)
		cout<<q.rpot[row]<<endl;
	getch();
	for(int row=1;row<=m.mu;row++)
		cout<<m.rpot[row]<<endl;
	getch();*/
	for(int arow=1;arow<=m.mu;arow++)
	{
		for(int row=1;row<=q.mu;row++)
		{
			int sum=0;
			for(int k1=m.rpot[arow];k1<m.rpot[arow+1];k1++)
				for(int k2=q.rpot[row];k2<q.rpot[row+1];k2++)
				{
					if(m.data[k1].y==q.data[k2].y)
					{
						sum+=m.data[k1].val*q.data[k2].val;
						break;
					}
				}
			if(sum)
			{
				t.data[h].val=sum;
				t.data[h].x=arow;
				t.data[h].y=row;
				h++;
			}
		}
	}
	t.tu=h;
}
int main()
{
	int r,c;
	while(cin>>r>>c)
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
		int num1[200],num2[200];
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(int i=0;i<m.tu;i++)
		{
			num1[m.data[i].x]++;
		}
		m.rpot[1]=0;
		for(int row=2;row<=m.mu+1;row++)
		{
			m.rpot[row]=m.rpot[row-1]+num1[row-1];
		}
		cin>>r>>c;
		t.mu=r;
		t.nu=c;
		t.tu=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>x;
				if(x)
				{
					t.data[t.tu].x=i;
					t.data[t.tu].y=j;
					t.data[t.tu].val=x;
					t.tu++;
				}
			}
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for(int i=0;i<t.tu;i++)
		{
			num1[m.data[i].x]++;
			num2[t.data[i].y]++;
		}
		t.cpot[1]=0;
		for(int col=2;col<=t.nu;col++)
		{
			t.cpot[col]=t.cpot[col-1]+num2[col-1];
		}
		t.rpot[1]=0;
		for(int row=2;row<=t.mu+1;row++)
		{
			t.rpot[row]=t.rpot[row-1]+num1[row-1];
		}
/*
		caculate();*/
		FastTransposeSMatrix();
		caculate();
		print(t);
	}
	return 0;
}
