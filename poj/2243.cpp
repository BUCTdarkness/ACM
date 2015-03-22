#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
bool vis[10][10];
int step[10][10];
struct Node{
    int x,y;
};
int d[8][2]={{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int sx,sy,ex,ey;
inline bool check(int x,int y){
    if(x>=0&&x<8&&y>=0&&y<8) return true;
    return false;
}
int bfs(){
    if(sx==ex&&sy==ey) return 0;
    queue<Node> que;
    CLR(vis);CLR(step);
    vis[sx][sy]=1;
    que.push((Node){sx,sy});
    while(!que.empty()){
        Node a=que.front();
        que.pop();
        for(int i=0;i<8;i++){
            Node b;
            b.x=a.x+d[i][0];b.y=a.y+d[i][1];
            if(check(b.x,b.y)&&!vis[b.x][b.y]){
                vis[b.x][b.y]=1;
                step[b.x][b.y]=step[a.x][a.y]+1;
                que.push(b);
                if(b.x==ex&&b.y==ey) return step[b.x][b.y];
            }
        }
    }
    return -1;
}
int main(){
    char str1[10],str2[10];
    while(~scanf("%s",str1)){
        sx=str1[0]-'a';sy=str1[1]-'1';
        scanf("%s",str2);
        ex=str2[0]-'a';ey=str2[1]-'1';
        printf("To get from %s to %s takes %d knight moves.\n", str1, str2, bfs());
    }
    return 0;
}


