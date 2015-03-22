#include<iostream>
using namespace std;
int x1[2000],y1[2000],x2[2000],y2[2000],a[2000];
struct xx
{
	int v;
	int s[10];
};
xx b[1010];
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(x1,0,sizeof(x1));
		memset(x2,0,sizeof(x2));
		memset(y1,0,sizeof(y1));
		memset(y2,0,sizeof(y2));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		if(n==0&&m==0) break;
		for(int i=0;i<n;i++)
		{
			cin>>x1[i]>>y1[i];
		}
		for(int i=0;i<m;i++)
		{
			cin>>x2[i]>>y2[i];
			for(int j=0;j<n;j++)
			{
				if(x2[i]==x1[j]&&y2[i]==y1[j])
				{
					a[i]++;
				}
				if(x2[i]==x1[j]+1&&y2[i]==y1[j])
				{
					a[i]++;
				}
				if(x2[i]==x1[j]&&y2[i]+1==y1[j])
				{
					a[i]++;
				}
				if(x2[i]==x1[j]+1&&y2[i]+1==y1[j])
				{
					a[i]++;
				}
			}
		}
		for(int j=0;j<n;j++)
		{
			int k=0;
			for(int i=0;i<m;i++)
			{
				if(x2[i]==x1[j]&&y2[i]==y1[j])
				{
					b[j].v++;
					b[j].s[k++]=i;
				}
				if(x2[i]==x1[j]+1&&y2[i]==y1[j])
				{
					b[j].v++;
					b[j].s[k++]=i;
				}
				if(x2[i]==x1[j]&&y2[i]+1==y1[j])
				{
					b[j].v++;
					b[j].s[k++]=i;
				}
				if(x2[i]==x1[j]+1&&y2[i]+1==y1[j])
				{
					b[j].v++;
					b[j].s[k++]=i;
				}
			}
		}
		int t=0,sum1=0,sum2=0;
//		for(int i=0;i<m;i++)
//		{
//			cout<<a[i]<<endl;
//			sum1+=a[i];
//		}
//		cout<<"sum1="<<sum1<<endl;
//		for(int j=0;j<n;j++)
//		{
//			cout<<"j="<<j<<endl;
//			cout<<b[j].v<<endl<<endl;
//			cout<<b[j].s[0]<<endl;
//			cout<<b[j].s[1]<<endl;
//			cout<<"ssssssssssssssssss"<<endl;
//			sum2+=b[j].v;
//		}
//		cout<<"sum2="<<sum2<<endl;
		for(int i=0;i<m;i++)
		{
			if(a[i]) t++;
		}
//		cout<<"t="<<t<<endl;
		for(int j=0;j<n;j++)
		{
			if(b[j].v>=2)
			{
				for(int r=0;r<j;r++)
				{	
					if(b[j].s[0]==b[r].s[0]&&b[j].s[1]==b[r].s[1])
					{
						t+=1; 
						break;
					}
				}
				if(a[b[j].s[0]]==2&&a[b[j].s[1]]==2)
				{		
					t++;
				}
				t--;
			}
		}
		cout<<n+m-t<<endl;
	}
	return 0;
}