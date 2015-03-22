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
void get_next(char *pat){
    memset(fail,-1,sizeof(fail));
    for(int i=1;pat[i];++i){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=pat[k+1];k=fail[k]);
        if(pat[k+1]==pat[i]) fail[i]=k+1;
    }
  //  for(int i=0;pat[i];i++) cout<<fail[i]<<endl;
}
int main(){
    int n,cas=0;
    while(~scanf("%d",&n)&&n){
        scanf("%s",str);
        get_next(str);
        int len=strlen(str);
        printf("Test case #%d\n",++cas);
        for(int i=0;i<len;i++){
            int plen=i-fail[i];
            if(i+1!=plen&&(i+1)%plen==0) printf("%d %d\n",i+1,(i/plen)+1);
        }
        printf("\n");
    }
    return 0;
}



