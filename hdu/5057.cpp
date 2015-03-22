#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
using namespace std;
#define lowbit(x) (x)&(-x)
#define CLR(A) memset(A,0,sizeof(A))
const int MAXN=100010;
int n,m;
int C[MAXN][10],a[MAXN],aa[MAXN],ans[MAXN];
struct Node{
    int kind,L,R,D,x,pos,value;
}que[MAXN];
void update(int kind,int p,int x){
    for(int i=p;i<=n;i+=lowbit(i)){
        if(kind==0) ++C[i][x];
        else if(kind==1) --C[i][x];
    }
}
int sum(int p,int x){
    int ret=0;
    for(int i=p;i>0;i-=lowbit(i)){
        ret+=C[i][x];
    }
    return ret;
}
int query(int L,int R,int x){
    return sum(R,x)-sum(L-1,x);
}
int Pow(int base,int k){
    int ret=1;
    while(k--) ret*=10;
    return ret;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            aa[i]=a[i];
        }
        char ord[10];
        for(int i=1;i<=m;i++){
            scanf("%s",ord);
            int x,y,L,R,D,P;
            if(ord[0]=='S'){
                scanf("%d%d",&x,&y);
                que[i].kind=1;que[i].pos=x;que[i].value=y;
            }
            else{
                scanf("%d%d%d%d",&L,&R,&D,&P);
                que[i].kind=0;que[i].L=L;que[i].R=R;que[i].D=D;que[i].x=P;
            }
        }
        for(int i=1;i<=10;i++){
            CLR(C);
            for(int j=1;j<=n;j++){
                a[j]=aa[j];
                int t1=a[j]/Pow(10,i-1)%10;
                update(0,j,t1);
            }
            for(int j=1;j<=m;j++){
                if(que[j].kind==1){
                    int t1=a[que[j].pos]/Pow(10,i-1)%10;
                     update(1,que[j].pos,t1);
                     int t2=que[j].value/Pow(10,i-1)%10;
                     update(0,que[j].pos,t2);
                     a[que[j].pos]=que[j].value;
                }
                else{
                    if(que[j].D==i){
                        ans[j]=query(que[j].L,que[j].R,que[j].x);
                    }
                }
            }
        }
        for(int i=1;i<=m;i++){
            if(que[i].kind==0){
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}
