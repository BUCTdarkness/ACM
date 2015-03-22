#include<iostream>
#include<algorithm>
using namespace std;
int zf[65][3],w[65][3],v[65][3],d[65][3205];
int main()
{
	int n,m,c,p,q,i,j,t;
	cin>>n>>m;
	n/=10;
	for(int i=1;i<=m;i++)
	{
		cin>>c>>p>>q;
		c/=10;
		if(q==0)
		{
			w[i][q]=c;
			v[i][q]=c*p;
		}
		else if(w[q][1]==0)
		{
			w[q][1]=c;
			v[q][1]=c*p;
		}
		else
		{
			w[q][2]=c;
			v[q][2]=c*p;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			d[i][j]=d[i-1][j];
			if(j>=w[i][0])
			{
				d[i][j]=max(d[i-1][j],d[i-1][j-w[i][0]]+v[i][0]);
			}
			if(j>=w[i][0]+w[i][1])
			{
				d[i][j]=max(d[i][j],d[i-1][j-w[i][0]-w[i][1]]+v[i][0]+v[i][1]);
			}
			if(j>=w[i][0]+w[i][2])
			{
				d[i][j]=max(d[i][j],d[i-1][j-w[i][0]-w[i][2]]+v[i][0]+v[i][2]);
			}
			if(j>=w[i][0]+w[i][1]+w[i][2])
			{
				d[i][j]=max(d[i][j],d[i-1][j-w[i][0]-w[i][1]-w[i][2]]+v[i][0]+v[i][1]+v[i][2]);
			} 
		}
	}
	cout<<d[m][n]*10<<endl;
	return 0;
}
