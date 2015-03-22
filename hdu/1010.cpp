#include <iostream>
#include <math.h>
using namespace std;
#define max 8
int anxix[]={0,-1,0,1},anxiy[]={-1,0,1,0};
int dx,dy;
int t,n,m,k;
char map[max][max];
bool escape;
void dfs(int sx,int sy,int utime)
{
    if((sx==dx)&&(sy==dy)&&(utime==t))
    {
       escape=true;
       return;
    }
    int temp=(t-utime)-abs(sx-dx)-abs(sy-dy);
    if(temp<0||temp&1)
    {
       escape=false;
       return;
    }
    for(int i=0;i<4;i++)
    {
       if((sx+anxix[i]<0)||(sx+anxix[i]>n-1)||(sy+anxiy[i]<0)||(sy+anxiy[i]>m-1))
           continue;
       if(map[anxix[i]+sx][anxiy[i]+sy]!='X')
       {
           map[anxix[i]+sx][anxiy[i]+sy]='X';
           dfs(anxix[i]+sx,anxiy[i]+sy,utime+1);
            map[anxix[i]+sx][anxiy[i]+sy]='.';
       }
       if(escape)
           break;
    }
}
int main()
{
    
    while(cin>>n>>m>>t && !(n==0 && m==0 && t==0))
    {       
        int sx,sy;
        int walnum=0;
        escape=false;
        for(int i1=0;i1<n;++i1)
        {
            for(int i2=0;i2<m;i2++)
            {
                
                cin>>map[i1][i2];//scanf("%c",&map[i1][i2]);居然少输入一次！！！！ 
                if(map[i1][i2]=='S')
                   {
                       sx=i1;
                       sy=i2;
                       map[sx][sy]='X';
                   }
                else 
                    if(map[i1][i2]=='D')
                        {
                           dx=i1;
                           dy=i2;
                        }
                    else if(map[i1][i2]=='X')
                                 walnum++;
            }
        }
        if(!(n*m-walnum<t))
            {
                dfs(sx,sy,0);
            }
        if(escape)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

