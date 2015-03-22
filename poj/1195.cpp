#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define  CLR(A) memset(A,0,sizeof(A))
const int MAX=1100;
int c[MAX][MAX];
int lowbit[MAX];
int n;
void add(int y,int x,int v){
	while(y<=n){
		int tmp=x;
		while(tmp<=n){
			c[y][tmp]+=v;
			tmp+=lowbit[tmp];
		}
		y+=lowbit[y];
	}
}
int query(int y,int x){
	int sum=0;
	while(y>0){
		int tmp=x;
		while(tmp>0){
			sum+=c[y][tmp];
			tmp-=lowbit[tmp];
		}
		y-=lowbit[y];
	}
	return sum;
}
int main(){
	for(int i=1;i<=MAX;i++) lowbit[i]=i&(i^(i-1));
	int cmd;
	while(scanf("%d",&cmd)!=EOF){
        int x,y,v;
        if(cmd==3) return 0;
		switch(cmd){
			case 0:
				scanf("%d",&n);
				CLR(c);
				break;
			case 1:
				scanf("%d%d%d",&x,&y,&v);
				add(y+1,x+1,v);
				break;
			case 2:
				int l,b,r,t;
				scanf("%d%d%d%d",&l,&b,&r,&t);
				l++;b++;r++;t++;
				int ret=query(t,r)-query(t,l-1)-query(b-1,r)+query(b-1,l-1);
				printf("%d\n",ret);
				break;
		}
	}
	return 0;
}
