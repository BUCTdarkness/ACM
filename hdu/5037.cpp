#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[200005];
int main(){
	int T,n,m,l;
	while(~scanf("%d",&T)){
		int nkase=0;
		while(T--){
			scanf("%d%d%d",&n,&m,&l);
			for(int i=1;i<=n;i++) scanf("%d",&a[i]);
			a[0]=0;a[++n]=m;
			sort(a,a+n);
			int k=l;
			int ans=0;
			for(int i=1;i<=n;i++){
				int x=(a[i]-a[i-1])%(l+1);
				int y=(a[i]-a[i-1])/(l+1);
				if(k+x>l){
					k=x;
					ans+=2*y+1;
				}
				else{
					k+=x;
					ans+=2*y;
				}
			}
			printf("Case #%d: %d\n",++nkase,ans);		
		}
	}
	return 0;
}
