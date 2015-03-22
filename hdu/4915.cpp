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
#define CLR(A)  memset(A,-1,sizeof(A))
typedef long long ll;
const int MAX=1000010;
char str[MAX];
int next[MAX],head=-1,cnt,tail=0;
int solve(){
    head=-1;cnt=0;tail=0;
    CLR(next);
    for(int i=0;str[i];i++){
        if(str[i]=='(') cnt++;
        else if(str[i]==')'){
            if(cnt==0){
                if(head==-1) return 0;
                cnt++;
                head=next[head];
            }
            else cnt--;
        }
        else{
            if(cnt>0){
                cnt--;
                next[tail]=i;
                tail=i;
                if(head==-1) head=i;
            }
            else{
                cnt++;
            }
        }
    }
    if(cnt!=0) return 0;
    else return 1;
}
int main(){
    while(~scanf("%s",str)){
        int len=strlen(str);
        bool ret=1;
        if(len&1){
            printf("None\n");continue;
        }
        ret=solve();
        if(ret==0){
            printf("None\n");continue;
        }
        if(head==-1){
            printf("Unique\n");continue;
        }
        str[head]='(';
        ret=solve();
        if(ret==0) printf("Unique\n");
        else printf("Many\n");
    }
    return 0;
}

