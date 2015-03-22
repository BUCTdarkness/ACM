//#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define N 1000010
#define SN 1510
int n,m,a[N];
map<int,int> hash[SN];
int flag[SN];
int B_s;
int B_n;

void r_hash(int _num) {
    int st=_num*B_s,ed=st+B_s-1;
    if(ed>=n) ed=n-1;
    hash[_num].clear();
    for(int i=st;i<=ed;i++) {
        hash[_num][a[i]]++;
    }
    flag[_num]=-1;
}


void r_build(int _num) {
    if(flag[_num]!=-1) {
        int st=_num*B_s;
        int ed=st+B_s-1;
        if(ed>=n) ed=n-1;
        for(int i=st;i<=ed;i++) a[i]=flag[_num];
        flag[_num]=-1;
    }
}


void build() {
    B_s = int(sqrt(n*1.0)+1.00001);
    B_n = n/B_s + ( n%B_s !=0 ) ;
    for(int i=0;i<B_n;i++) {
        r_hash(i);
    }
}

void up_block(int _num,int sta,int end,int z) {
    if(z==flag[_num]) return;
    r_build(_num);
    int st=_num*B_s+sta;
    int ed=_num*B_s+end;
    if(ed>=n) ed=n-1;
    for(int i=st;i<=ed;i++) {
        a[i]=z;
    }
    r_hash(_num);
}

int g_block(int _num,int sta,int end,int z) {
    if(flag[_num]!=-1) {
        return z==flag[_num]?end-sta+1:0;
    }
    int st=_num*B_s+sta,ed=_num*B_s+end;
    if(ed>=n) ed=n-1;
    int ret=0;
    for(int i=st;i<=ed;i++) {
        if(a[i]==z) ret++;
    }
    return ret;
}
void update(int l,int r,int z) {
    int lx=l/B_s;
    int ly=l%B_s;
    int rx=r/B_s;
    int ry=r%B_s;
    if(lx==rx){
        up_block(lx,ly,ry,z);
    }else{
        up_block(lx,ly,B_s-1,z);
        up_block(rx,0,ry,z);
    }
    for(int i=lx+1;i<=rx-1;i++) {
        flag[i]=z;
    }
}

int query(int l,int r,int z) {
    int lx=l/B_s;
    int ly=l%B_s;
    int rx=r/B_s;
    int ry=r%B_s;
    int ret=0;

    if(lx==rx){
        ret+=g_block(lx,ly,ry,z);
    }else{
        ret+=g_block(lx,ly,B_s-1,z);
        ret+=g_block(rx,0,ry,z);
    }
    for(int i=lx+1;i<=rx-1;i++) {
        if(flag[i]!=-1){
            if(z==flag[i]) ret+=B_s;
        }else {
            if(hash[i].find(z)!=hash[i].end()) ret+=hash[i][z];
        }
    }
    return ret;
}

int main() {
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m)!=EOF) {
    	if(n==0&&m==0) break;
        for(int i=0;i<n;i++) a[i]=2;
        build();
        for(int i=0;i<m;i++) {
            int l,r,z;
            char cmd[5];
     		getchar();
            scanf("%s%d%d",cmd,&l,&r);
            if(cmd[0]=='P') {
            	scanf("%d",&z);
                update(l-1,r-1,z);
            }else if(cmd[0]=='Q'){
            	bool flag=0;
       			for(int c=1;c<=30;c++){
       				int t=query(l-1,r-1,c);
					if(t>0) {
						if(flag==0){
							printf("%d",c);flag=1;
						}
						else printf(" %d",c);
					}
       			}
				printf("\n");
            }
        }
    }
    return 0;
}
