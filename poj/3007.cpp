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
const int MAX=100;
map<string,bool> mp;
char word[MAX*100][MAX];
int cnt=0;
void ins(char ch[]){
    for(int i=0;i<cnt;i++) if(strcmp(word[i],ch)==0) return ;
    strcpy(word[cnt++],ch);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        while(n--){
            cnt=0;
            char str[MAX],tmp1[MAX];
            scanf("%s",str);
            int len=strlen(str);
            for(int i=0;i<len-1;i++){

                strcpy(tmp1,str); ins(tmp1);

                reverse(tmp1,tmp1+i+1); ins(tmp1);

                reverse(tmp1+i+1,tmp1+len); ins(tmp1);

                reverse(tmp1,tmp1+i+1); ins(tmp1);

                strcpy(tmp1,str);reverse(tmp1,tmp1+len);ins(tmp1);

                reverse(tmp1,tmp1+i+1); ins(tmp1);

                reverse(tmp1+i+1,tmp1+len); ins(tmp1);

                reverse(tmp1,tmp1+i+1); ins(tmp1);
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
