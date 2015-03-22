#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=100010;
struct Matrix{
    long  x,y;
    int v;
}M[MAX];
map<long,long> mpr;//记录每个x开始的位置
map<long,long> prec;//记录C对应的是原数组中的y的值
bool cmp(Matrix a,Matrix b){
    if(a.x==b.x) return a.y<b.y;
    else return a.x<b.x;
}
int main(){
    int W,ncase=0;
    while(~scanf("%d",&W)){
        while(W--){
            printf("Case #%d:\n",++ncase);
            mpr.clear();prec.clear();
            long n,m,k;
            scanf("%ld%ld%ld",&n,&m,&k);
            for(ll i=1;i<=k;++i){
                scanf("%ld%ld%d",&M[i].x,&M[i].y,&M[i].v);
                M[i].x++;M[i].y++;
            }
            sort(M+1,M+k+1,cmp);
 			int prex=0;
            for(int i=1;i<=k;i++){
            	if(M[i].x!=prex){
            		mpr[M[i].x]=i;
            		prex=M[i].x;
            	}
            	prec[M[i].y]=M[i].y;
            }
            long t;
            scanf("%ld",&t);
            while(t--){
                long q,a,b;
                scanf("%d%ld%ld",&q,&a,&b);
                a++;b++;
                switch(q){
                case 1:
                	if(mpr[a]&&mpr[b]){
                		swap(mpr[a],mpr[b]);
                	}
                    break;
                case 2:
                    if(prec[a]&&prec[b]){
                        swap(prec[a],prec[b]);
                    }
                    break;
                case 3:
                	int prex=M[mpr[a]].x,i;
                    for(i=mpr[a];M[i].x==prex&&i<=k;i++){
                    	if(M[i].y==prec[b]){
                    		printf("%d\n",M[i].v);
                    		break;
                    	}
                    }
                    if(i>n||M[i].x!=prex)printf("0\n");
                }
            }
        }
    }
    return 0;
}

