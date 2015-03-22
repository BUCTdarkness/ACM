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
#define LL long long
#define MAXN 200100
struct Node{
    int left,right,v;
};Node Tree[MAXN<<2];
void Build(int id,int left,int right){
    Tree[id].v=0;
    Tree[id].left=left;
    Tree[id].right=right;
    if(left==right) return;
    int mid=(left+right)>>1;
    Build(id<<1,left,mid);
    Build(id<<1|1,mid+1,right);
}
void Update(int id,int pos,int add){
    int left=Tree[id].left,right=Tree[id].right;
    if(left==right){
        Tree[id].v+=add;
        return;
    }
    int mid=(left+right)>>1;
    if(mid>=pos)
        Update(id<<1,pos,add);
    else
        Update(id<<1|1,pos,add);
   Tree[id].v=min(Tree[id<<1].v,Tree[id<<1|1].v);
}
int Query(int id,int Qleft,int Qright){
    int left=Tree[id].left,right=Tree[id].right;
    if(left>=Qleft && right<=Qright)
        return Tree[id].v;
    int mid=(left+right)>>1;
    if(mid>=Qright)
        return Query(id<<1,Qleft,Qright);
    else if(mid<Qleft)
        return Query(id<<1|1,Qleft,Qright);
    int r1=Query(id<<1,Qleft,Qright),r2=Query(id<<1|1,Qleft,Qright);
    return min(r1,r2);;
}
int A[MAXN];
int F[MAXN];
int main(){
    int N,K;
    while(~scanf("%d%d",&N,&K)){
        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);
        Build(1,0,N);
        memset(F,0,sizeof(F));
        int i;
        for(i=1;i<=N;i++){
            F[A[i]]++;
            Update(1,A[i],1);
            if(A[i]==0)    continue;
            int ans=Query(1,0,A[i]-1);
            if(ans<F[A[i]]-K) break;
        }
        printf("%d\n",i-1);
    }
}
