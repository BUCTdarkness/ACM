#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
using namespace std;
#define lowbit(x) (x)&(-x)
#define CLR(A) memset(A,0,sizeof(A))
int main(){
    char str[200];
    char tmp[200];
    int a,b;
    while(gets(str)){
        cin>>a>>b;
        getchar();
        int c=atoi(str);
        sprintf(tmp,"%d",c);
      //  cout<<tmp<<endl;
        if(strcmp(tmp,str)==0&&c>=a&&c<=b) puts("YES");
        else puts("NO");
    }
    return 0;
}

