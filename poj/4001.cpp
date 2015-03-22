#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
char org[20][20];
const int x[4]={1,0,-1,0};
const int y[4]={0,1,0,-1};
bool killed(int X,int Y){
    for(int i=0;i<4;i++){
        int tx=X+x[i],ty=Y+y[i];
        bool tmp=false;//是否隔了一个子
        if(x[i]){ //判马！
            int xx=tx+x[i];
            if((org[tx][ty-1]==0&&org[xx][ty-1]=='H')||(org[tx][ty+1]==0&&org[xx][ty+1]=='H'))
                return true;
        }else{
            int yy=ty+y[i];
            if((org[tx-1][ty]==0&&org[tx-1][yy]=='H')||(org[tx+1][ty]==0&&org[tx+1][yy]=='H'))
                return true;
        }
        while(tx>=1&&tx<=10&&ty>=1&&ty<=9){//单方向扫描
            if((!tmp&&(org[tx][ty]=='R'||org[tx][ty]=='G'))||(tmp&&org[tx][ty]=='C')){
                return true;
            }
            if(org[tx][ty]!=0){
                if(tmp) break;
                tmp=true;
            }
            tx+=x[i];ty+=y[i];
        }
    }
    return false;
}
int main(){
    int n,X,Y;
    while(~scanf("%d%d%d",&n,&X,&Y)){
        if(n==0&&X==0&&Y==0) break;
        CLR(org);
        char c;
        int tx,ty;
        bool flag=false;
        for(int i=0;i<n;i++){
            scanf(" %c%d%d",&c,&tx,&ty);
            org[tx][ty]=c;
        }
        for(int i=0;i<4;i++){
            tx=X+x[i];ty=Y+y[i];
            if(tx<1||tx>3||ty<4||ty>6) continue;
            if(killed(tx,ty)==0){
                flag=true;break;
            }
        }
        printf("%s\n",flag?"NO":"YES");
    }
    return 0;
}
