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
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define CPY(A,B) memcpy(A,B,sizeof(B))
int map[10][10],vis[10][10];
int deep,n;
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
bool check(int x,int y){return x>=0&&x<n&&y>=0&&y<n;}
void change_color(int x,int y,int color){
    for(int i=0;i<4;i++){
        int tx=x+dx[i],ty=y+dy[i];
        if(check(tx,ty)){
            if(vis[tx][ty]==1) continue;
            if(map[tx][ty]==color){
                vis[tx][ty]=1;
                change_color(tx,ty,color);
            }
            else{
                vis[tx][ty]=2;
            }
        }
    }
}
int h(){
    int cnt=0;
    bool mark[10];
    CLR(mark);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j]!=1) mark[map[i][j]]=true;
        }
    }
    for(int i=0;i<=5;i++) if(mark[i]) cnt++;
    return cnt;
}
bool dfs(int d){
    int t=h();
    if(d==deep) return t==0?true:false;
    if(d+t>deep) return false;
    for(int i=0;i<=5;i++){
        int cnt=0;int tvis[10][10];
        CPY(tvis,vis);
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++){
                if(map[j][k]!=i) continue;
                if(vis[j][k]==2){
                    vis[j][k]=1;
                    change_color(j,k,i);
                    cnt++;
                }
            }
        if(cnt>0&&dfs(d+1)) return true;
        CPY(vis,tvis);
    }
    return false;
}
int main(){
    while(scanf("%d",&n)!=EOF,n){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                scanf("%d",&map[i][j]);
            }
        CLR(vis);
        deep=0;vis[0][0]=1;
        change_color(0,0,map[0][0]);
        while(true){
            if(dfs(0)) break;
            deep++;
        }
        printf("%d\n",deep);
    }
    return true;
}






