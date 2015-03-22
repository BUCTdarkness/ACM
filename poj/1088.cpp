#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
const int MAX=120;
struct Dot{
	int x,y,h;
};
vector<Dot> l;
int dp[MAX][MAX];
int h[MAX][MAX];
bool cmp(Dot a,Dot b){
	return a.h<b.h;
}
int main(){
    int m,n;
	while(cin>>m>>n){
		int cnt=0;
		memset(h,0,sizeof(h));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&h[i][j]);
				l.push_back((Dot){i,j,h[i][j]});
				dp[i][j]=1;
			}
		}
		sort(l.begin(),l.end(),cmp);
		for(int i=0;i<m*n;i++){
			int x=l[i].x,y=l[i].y;
			if(h[x][y]<h[x][y+1]){
				dp[x][y+1]=max(dp[x][y+1],dp[x][y]+1);
			}
			if(h[x][y]<h[x][y-1]){
				dp[x][y-1]=max(dp[x][y-1],dp[x][y]+1);
			}
			if(h[x][y]<h[x+1][y]){
				dp[x+1][y]=max(dp[x+1][y],dp[x][y]+1);
			}
			if(h[x][y]<h[x-1][y]){
				dp[x-1][y]=max(dp[x-1][y],dp[x][y]+1);
			}
		}
		int ret=-1;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				ret=max(ret,dp[i][j]);
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
