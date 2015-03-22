#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;
const int MAX=1000100;
int fail[MAX];
int kmp(char *str,char *pat){
    int ret=0;
    memset(fail,-1,sizeof(fail));
    for(int i=1;pat[i];i++){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]){
            fail[i]=k+1;
        }
    }
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
char str1[MAX],str2[MAX];
int main(){
    int t;
    while(cin>>t){
        while(t--){
            cin>>str1>>str2;
            cout<<kmp(str2,str1)<<endl;
        }
    }
    return 0;
}
