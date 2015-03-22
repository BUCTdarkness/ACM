#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define cls(x) memset(x,0,sizeof(x))
using namespace std;
const int x=300;
const int MAXN=1000010;
int n,m,pos,len;
unsigned long long H[MAXN],xp[MAXN];
unsigned long long hash[MAXN];
int rank[MAXN];
bool possible(int L)
{
    for(int i=0;i<n-L+1;i++)
        hash[i]=H[i]-H[i+L]*xp[L];
    for(int i=0;i<len-L+1;i++)
    	for(int j=len;j<n-L+1;j++)
    	{
	    	if(i==j)
	    		continue;
    		if(hash[i]==hash[j])
    			return true;
	    }
    return false;
}
char s[2*MAXN];
int main()
{
    while(cin>>s)
    {
        n=strlen(s);
        len=n;
        cin>>(s+len);
        n=strlen(s);
        H[n]=0;
        for(int i=n-1;i>=0;i--) H[i]=H[i+1]*x+(s[i]-'a');
        xp[0]=1;
        for(int i=1;i<=n;i++) xp[i]=xp[i-1]*x;
        if(!possible(1)) printf("none\n");
        else
        {
            int l=1,r=n+1;
            while(r-l>1)
            {
                int m=(l+r)/2;
                if(possible(m)) l=m;else r=m;
            }
            possible(l);
            printf("%d\n",l);
        }
    }
    return 0;
}
