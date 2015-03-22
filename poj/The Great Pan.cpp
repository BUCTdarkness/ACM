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
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
char g[1500100];
int main(){
    int n;
    long long ret,cntf,cntp;
    while(~scanf("%d",&n)){
        ret=1;
        cntf=0;cntp=0;
        bool f1=false,f2=false;
        bool doge=false;
        getchar();
        while(n--){
            gets(g);
            int len=strlen(g);
            for(int i=0;i<len;i++){
                if(ret>100000){
                    doge=true;
                    break;
                }
                if(g[i]=='{'){
                    f1=true;
                    continue;
                }
                if(g[i]=='}'){
                    f1=false;
                    ret*=(cntf+1);
                    cntf=0;
                    continue;
                }
                if(f1&&g[i]!='}'){
                    if(g[i]=='|') cntf++;
                    continue;
                }
                if(f2&&g[i]!='$'){
                    bool flag=false;
                    while(g[i]==' '){
                        i++;cntp++;
                        flag=true;
                    }
                    if(flag){
                        i--;
                        ret*=(cntp+1);
                        cntp=0;
                    }
                    continue;
                }
                if(g[i]=='$'){
                    if(f2==false){
                        f2=true;
                        continue;
                    }
                    else{
                     //   cout<<"cc"<<endl;
                        f2=false;
                        cntp=0;
                        continue;
                    }
                }
            }
        }
        if(doge){
            cout<<"doge"<<endl;
        }else  {
            cout<<ret<<endl;
        }
    }
    return 0;
}


