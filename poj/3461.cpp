#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
#define CLR  memset(A,0,sizeof(A))
const int MAX=1000005;
char str[MAX],pat[MAX];
int fail[MAX];
int kmp(char *str,char *pat){
    memset(fail,-1,sizeof(fail));
    for(int i=1;pat[i];i++){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]){
            fail[i]=k+1;
        }
    }
    int ret=0;
    int i=0,j=0;
    while(str[i]){
        if(pat[j]==str[i]){++i;++j;}
        else if(j==0) ++i;
        else j=fail[j-1]+1;
        if(!pat[j]){
            j=fail[j-1]+1;
            ret++;
        }
    }
    return ret;
}
int main(){
    int t;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%s%s",str,pat);
            printf("%d\n",kmp(pat,str));
        }
    }
    return 0;
}
