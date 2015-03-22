#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
struct Node{
    int time,num;
}cur[2504];
struct DEQ{
    int pos,v;
}que[2504];
char month[13][5] = { "", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" ,"Dec"};
int day[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
inline int find(char *s){for(int i=1;i<=12;i++) if(strcmp(s,month[i])==0) return i;}
inline int judge(int x){return x%400==0||x%4==0&&x%100;}
inline int solve(int x,int y,int z,int w){
	bool p;int ret=0;
	for(int i=2000;i<x;i++){
		p=judge(i);
		ret+=365*24;
		if(p) ret+=24;
	}
	p=judge(x);
	for(int i=1;i<y;i++) ret+=day[p][i]*24;
	ret+=(z-1)*24+w;
	return ret;
}
int main(){
    int n,m,t,s;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        char mon[20];
        int x,y,z,w;
        for(int i=0;i<n;i++){
            scanf("%s%d%d%d%d",mon,&z,&x,&w,&cur[i].num);
            cur[i].time=solve(x,find(mon),z,w);
        }
        scanf("%d%d",&t,&s);
        __int64 ans=0;
        int head=0,tail=-1,k=0;
        for(int i=0;i<m;i++){
            int x;scanf("%d",&x);
            while(head<=tail&&que[tail].v+(i-que[tail].pos)*s>=x) tail--;
            que[++tail].pos=i;que[tail].v=x;
            while(k<n&&cur[k].time==i){
                while(head<=tail&&i-que[head].pos>t) head++;
                ans+=(que[head].v+(i-que[head].pos)*s)*cur[k++].num;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
