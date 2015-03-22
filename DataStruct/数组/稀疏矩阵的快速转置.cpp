#include<iostream>
#include<algorithm>
#include<string.h>
//#include<conio.h>
#define MAX_LEN 12555 
using namespace std;
struct Matrix
{
	int x;
	int y;
	int val;
};
Matrix m[MAX_LEN],t[MAX_LEN];
int len1,len2,r,c;
void FastTransposeSMatrix()
{
	int col;
	int num[200],cpot[200];
	if(len1)
	{
		for(col=1;col<=c;col++)
		{
			num[col]=0;
		}
		for(int i=0;i<len1;i++)
		{
			num[m[i].y]++;
		}
		cpot[1]=0;
		for(col=2;col<=c;col++)
		{
			cpot[col]=cpot[col-1]+num[col-1];
		}
		for(int i=0;i<len1;i++)
		{
			col=m[i].y;
			int pos=cpot[col];
			t[pos].x=m[i].y;
			t[pos].y=m[i].x;
			t[pos].val=m[i].val;
			cpot[col]++;
		}
	}
}
void print()
{
	int k=0;
	for(int row=1;row<=c;row++)
	{
		for(int col=1;col<=r;col++)
		{
			int flag=0;
			if(t[k].x==row&&t[k].y==col)
			{
				flag=1;
				cout<<t[k].val;
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
	while(cin>>r>>c)
	{
		int x;
		len1=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				cin>>x;
				if(x)
				{
					m[len1].x=i;
					m[len1].y=j;
					m[len1].val=x;
					len1++;
				}
			}
		FastTransposeSMatrix();
/*

		for(int i=0;i<len1;i++)
			cout<<t[i].val<<" "<<t[i].x<<" "<<t[i].y<<endl;
			getch();*/
		print();
	}
	return 0;
}



