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
const int MAX=400010;
char str[MAX];
int fail[MAX];
void get_next(char *pat){
    memset(fail,-1,sizeof(fail));
    for(int i=1;pat[i];++i){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]) fail[i]=k+1;
    }
 //   for(int i=0;pat[i];i++) cout<<fail[i]<<endl;
}
void solve(int x){
    if(x<0) return;
    solve(fail[x]);
    printf("%d ",x+1);
}
int main(){
    while(~scanf("%s",str)){
        get_next(str);
        solve(strlen(str)-1);
        printf("\n");
    }
    return 0;
}

