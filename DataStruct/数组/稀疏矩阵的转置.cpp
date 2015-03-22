#include<iostream>
#include<string.h>
using namespace std;
struct Matrix
{
	int x;
	int y;
	int val;
};
Matrix m[12555],t[12555];
int q,p,r,c;
void TransposeSMatrix()
{ 
	p=0;
	for(int col=1;col<=c;col++)
	{
		for(int i=0;i<q;i++)
		{
			if(m[i].y==col)
			{
				t[p].x=m[i].y;
				t[p].y=m[i].x;
				t[p].val=m[i].val;
				p++;
			}
		}
	}
}
void print()
{
	int k=0;
	for(int row=1;row<=c;row++)
	{
		for(int i=0;i<r;i++)
		{
			int flag=0;
			if(t[k].y==i+1&&t[k].x==row)
			{
				cout<<t[k].val;
				k++;
				flag=1;
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
	while(cin>>r>>c)
	{
		int x;
		q=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>x;
				if(x)
				{
					m[q].x=i;
					m[q].y=j;
					m[q].val=x;
					q++;
				}
			}
		TransposeSMatrix(); 
/*
		for(int i=0;i<p;i++)
			cout<<t[i].val<<" "<<t[i].x<<" "<<t[i].y<<endl;
			getch();*/
		print();
	}
	return 0;
}
