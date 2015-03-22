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
#define MAXN 1000010
using namespace std;
struct Node{
    int left,right,color;
    bool same;
};Node Tree[MAXN*4];
void Build(int id,int left,int right){
    Tree[id].left=left;
    Tree[id].right=right;
    Tree[id].same=1;
    Tree[id].color=4;
    if(left==right)
        return;
    int mid=(left+right)>>1;
    Build(id<<1,left,mid);
    Build(id<<1|1,mid+1,right);
}
void Update(int id,int L,int R,int color){
    if(L<=Tree[id].left && R>=Tree[id].right){
        Tree[id].same=1;
        Tree[id].color=(1<<color);
        return;
    }
    if(Tree[id].same==1){
        Tree[id<<1].same=1;
        Tree[id<<1|1].same=1;
        Tree[id<<1].color=Tree[id].color;
        Tree[id<<1|1].color=Tree[id].color;
        Tree[id].same=0;
    }
    int mid=(Tree[id].left+Tree[id].right)>>1;
    if(L<=mid)
        Update(id<<1,L,R,color);
    if(R>mid)
        Update(id<<1|1,L,R,color);
    Tree[id].color=Tree[id<<1].color|Tree[id<<1|1].color;
}
//int vis[50];
int Query(int id,int L,int R){
    if(Tree[id].left==L && Tree[id].right==R){
        return Tree[id].color;
    }
    if(Tree[id].same==1){
        Tree[id<<1].same=1;
        Tree[id<<1|1].same=1;
        Tree[id<<1].color=Tree[id].color;
        Tree[id<<1|1].color=Tree[id].color;
        Tree[id].same=0;
    }
    int mid=(Tree[id].left+Tree[id].right)>>1;
    if(L>mid)
        return Query(id<<1|1,L,R);
    else if(R<=mid)
        return Query(id<<1,L,R);
    else
        return Query(id<<1,L,mid)|Query(id<<1|1,mid+1,R);
}
int Print(int x){
    int cnt=0,cntcolor=0,ans[50];
    while(x){
        if(x&1)
            ans[cntcolor++]=cnt;
        x>>=1;
        cnt++;
    }
    printf("%d",ans[0]);
    for(int i=1;i<cntcolor;i++){
        printf(" %d",ans[i]);
    }
    puts("");
}
int N,M;
int main(){
    while(~scanf("%d%d",&N,&M)){

        if(N==0 && M==0)    break;
        Build(1,1,N);
 //   cout<<N<<' '<<M<<endl;
        char cmd[5];
        int x,y,co;
        for(int i=0;i<M;i++){
            scanf("%s",cmd);
            if(cmd[0]=='P'){
                scanf("%d%d%d",&x,&y,&co);
                Update(1,x,y,co);
            }
            else if(cmd[0]=='Q'){
                scanf("%d%d",&x,&y);
                int sum=Query(1,x,y);
                Print(sum);
            }
        }
    }
    return 0;
}
