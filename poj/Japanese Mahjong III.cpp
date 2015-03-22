#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=50;
int a[10][10];
char str[MAX];
int main(){
    while(~scanf("%s",str)){
        CLR(a);int len=strlen(str);
        for(int i=0;i<len-1;i++){
            if(str[i+1]=='p') a[0][str[i]-'0']++;
            if(str[i+1]=='s') a[1][str[i]-'0']++;
            if(str[i+1]=='m') a[2][str[i]-'0']++;
            if(str[i+1]=='z') a[3][str[i]-'0']++;
        }
        bool flag=0;
        for(int i=0;i<4;i++){
            for(int j=1;j<10;j++){
                if(a[i][j]&&a[i][j]!=2){
                    flag=1;break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"Seven Pairs"<<endl;
        else{
            if(a[0][1]&&a[0][9]&&a[1][1]&&a[1][9]&&a[2][1]&&a[2][9]&&a[3][1]&&a[3][2]&&a[3][3]&&a[3][4]&&a[3][5]&&a[3][6]&&a[3][7]){
                if(a[0][1]==2||a[0][9]==2||a[1][1]==2||a[1][9]==2||a[2][1]==2||a[2][9]==2||a[3][1]==2||a[3][2]==2||a[3][3]==2||a[3][4]==2||a[3][5]==2||a[3][6]==2||a[3][7]==2){
                    cout<<"Thirteen Orphans"<<endl;
                }
                else cout<<"Neither!"<<endl;
            }
            else cout<<"Neither!"<<endl;
        }
    }
    return 0;
}
