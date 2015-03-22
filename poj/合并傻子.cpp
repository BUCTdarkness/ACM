#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#include<vector>
#include<stack>
#include<set>
using namespace std;
const int MAX=1010;
const int INF=1000000000;
int f[MAX][MAX];
int n,m;
int s[MAX];
int a[MAX];
void dp1()
{
    memset(f,0,sizeof(f));
	for(int i=1;i<=n-1;i++)
        f[i][i+1]=a[i]+a[i+1];
    for(int p=2;p<=n-1;p++)
        for(int i=1;i<=n-p;i++)
        {
            int j=i+p;
            f[i][j]=-INF;
            for(int k=i;k<=j-1;k++)
                f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
}
void dp2()
{
    memset(f,0,sizeof(f));
	for(int i=1;i<=n-1;i++)
        f[i][i+1]=a[i]+a[i+1];
    for(int p=2;p<=n-1;p++)
        for(int i=1;i<=n-p;i++)
        {
            int j=i+p;
            f[i][j]=INF;
            for(int k=i;k<=j-1;k++)
                f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+s[j]-s[i-1]);
        }
}
int main()
{

    while(cin>>n>>m)
    {
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
		dp1();
		if(f[1][n]<m)
		{
			printf("It is easy\n");
			continue;
		}
		dp2();
		if (f[1][n]>m) printf("I am..Sha...X\n");
		else printf("I will go to play WarIII\n");
    }
    return 0;
}
