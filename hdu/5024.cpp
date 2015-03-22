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
#define MAXN 110
#define MAXM 10
#define STATUS 32
#define inf 0x3f3f3f3f
using namespace std;
char mp[MAXN][MAXN];
struct Node{
    int x,y,key,st,step;
};
int N,M;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int step[MAXN][MAXN][MAXM][STATUS];
int Snake[MAXN][MAXN];
int ANS=inf;
void BFS(int x,int y){
    memset(step,-1,sizeof(step));
    queue<Node>Q;
    Node now;
    now.x=x;now.y=y;now.st=0;now.key=0;now.step=0;
    step[x][y][0][0]=0;
    Q.push(now);
    while(!Q.empty()){
        now=Q.front();
        Q.pop();
        int x=now.x,y=now.y,st=now.st,key=now.key,sstep=now.step;
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0],ty=y+dir[i][1];
            if(tx<0 || tx>=N || ty<0 || ty>=N || mp[tx][ty]=='#')    continue;
            if(mp[tx][ty]=='.' || mp[tx][ty]=='K'){
                if(step[tx][ty][key][st]==-1 || step[tx][ty][key][st]>sstep+1){
                    Node t;
                    step[tx][ty][key][st]=sstep+1;
                    t.x=tx;t.y=ty;t.st=st;t.key=key;t.step=sstep+1;
                    Q.push(t);
                }
            }
            else if(mp[tx][ty]=='S'){
                int Snum=Snake[tx][ty],Sst=1<<Snum,tstep=sstep;
                if((Sst&st)==0)
                    tstep+=2;
                else
                    tstep+=1;
                if(step[tx][ty][key][st|Sst]==-1 || step[tx][ty][key][st|Sst]>tstep){
                    Node t;
                    step[tx][ty][key][st|Sst]=tstep;
                    t.x=tx;t.y=ty;t.st=st|Sst;t.key=key;t.step=tstep;
                    Q.push(t);
                }
            }
            else if(mp[tx][ty]=='T'){
                if(key==M ){ANS=min(ANS,sstep+1);}
                if(step[tx][ty][key][st]==-1 || step[tx][ty][key][st]>sstep+1){
                    Node t;
                    step[tx][ty][key][st]=sstep+1;
                    t.x=tx;t.y=ty;t.st=st;t.key=key;t.step=sstep+1;
                    Q.push(t);
                }
            }
            else if(mp[tx][ty]>='0' && mp[tx][ty]<='9'){
                int nowkey=mp[tx][ty]-'0';
                int tkey=key;
                if(key+1==nowkey){
                    tkey++;
                }
                if(step[tx][ty][tkey][st]==-1 || step[tx][ty][tkey][st]>sstep+1){
                    step[tx][ty][tkey][st]=sstep+1;
                    Node t;
                    t.x=tx;t.y=ty;t.st=st;t.key=tkey;t.step=sstep+1;
                    Q.push(t);
                }
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&N,&M)){
        if(N==0 && M==0)    break;
        for(int i=0;i<N;i++)
            scanf("%s",mp[i]);
        int scnt=0,stx,sty;
        memset(Snake,0,sizeof(Snake));
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mp[i][j]=='S')
                    Snake[i][j]=scnt++;
                if(mp[i][j]=='K'){
                    stx=i;sty=j;
                }
            }
        }
        ANS=inf;
        BFS(stx,sty);
        if(ANS==inf)
            printf("impossible\n");
        else
            printf("%d\n",ANS);
    }
    return 0;
}
