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
int fail[MAX];
char str[MAX];
int kmp(char *pat){
    int len=strlen(pat);
    memset(fail,-1,sizeof(fail));
    for(int i=1;pat[i];i++){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]){
            fail[i]=k+1;
        }
    }
  //  for(int i=0;i<=len;i++) cout<<fail[i]<<endl;
    int t=len-1-fail[len-1];
    if(len%t==0) return len/t;
    return 1;
}
int main(){
    while(~scanf("%s",str)&&str[0]!='.'){
        cout<<kmp(str)<<endl;
    }
    return 0;
}
