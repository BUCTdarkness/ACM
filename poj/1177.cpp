#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
struct Node{
    int st,ed,m,lbd,rbd;
    int sequence_line,cnt;
}ST[40005];
void build(int st,int ed,int v){
    ST[v].st=st;ST[v].ed=ed;
    ST[v].m=ST[v].lbd=ST[v].rbd=0;
    ST[v].sequence_line=ST[v].cnt=0;
    if(ed-st>1){
        int mid=(st+ed)>>1;
        build(st,mid,2*v+1);
        build(mid,ed,2*v+2);
    }
}
inline void UpDate(int v){
    if(ST[v].cnt>0){
        ST[v].m=ST[v].ed-ST[v].st;
        ST[v].lbd=ST[v].rbd=1;
        ST[v].sequence_line=1;
        return;
    }
    if(ST[v].ed-ST[v].st==1){
        ST[v].m=0;
        ST[v].lbd=ST[v].rbd=0;
        ST[v].sequence_line=0;
    }
    else{
        int left=2*v+1,right=2*v+2;
        ST[v].m=ST[left].m+ST[right].m;
        ST[v].sequence_line=ST[left].sequence_line+ST[right].sequence_line-(ST[left].rbd&ST[right].lbd);
        ST[v].lbd=ST[left].lbd;
        ST[v].rbd=ST[right].rbd;
    }
}
void Insert(int s,int e,int v){
    if( s<=ST[v].st && e>=ST[v].ed){
        ST[v].cnt++;
        UpDate(v);
        return;
    }
    int mid=(ST[v].st+ST[v].ed)>>1;
    if(s<mid) Insert(s,e,2*v+1);
    if(e>mid) Insert(s,e,2*v+2);
    UpDate(v);
}
void Delete(int st,int ed,int v){
    if(st<=ST[v].st&&ed>=ST[v].ed){
        ST[v].cnt--;
        UpDate(v);
        return;
    }
    int mid=(ST[v].st+ST[v].ed)>>1;
    if(st<mid) Delete(st,ed,2*v+1);
    if(ed>mid) Delete(st,ed,2*v+2);
    UpDate(v);
}
struct line{
    int x,y1,y2;bool d;
}a[10003];
bool cmp(line t1,line t2){return t1.x<t2.x;}
void cal_c(int n){
    int i,j,k,t2=0,sum=0;
    a[n]=a[n-1];
    for(int i=0;i<n;i++){
        if(a[i].d==1) Insert(a[i].y1,a[i].y2,0);
        else Delete(a[i].y1,a[i].y2,0);
        sum+=ST[0].sequence_line*(a[i+1].x-a[i].x)*2;
        sum+=abs(ST[0].m-t2);
        t2=ST[0].m;
    }
    printf("%d\n",sum);
}
int main(){
    int n,x1,x2,y1,y2,i,j,suby,upy;
    while(~scanf("%d",&n)){
        j=0;
        suby=10000;upy=-10000;
        for(i=0;i<n;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            a[j].x=x1;a[j].y1=y1;a[j].y2=y2;a[j].d=1;
            j++;
            a[j].x=x2;a[j].y1=y1;a[j].y2=y2;a[j].d=0;
            j++;
            if(suby>y1) suby=y1;
            if(upy<y2) upy=y2;
        }
        sort(a,a+j,cmp);
        build(suby,upy,0);
        cal_c(j);
    }
    return 0;
}
