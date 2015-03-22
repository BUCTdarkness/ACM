#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
const char data[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int find(char *str){
    for(int i=0;i<10;i++){
        if(strcmp(data[i],str)==0) return i;
    }
}
int main(){
    char s[50];
    while(true){
        int a=0;
        while(~scanf("%s",s)&&s[0]!='+') a=a*10+find(s);
        int b=0;
        while(~scanf("%s",s)&&s[0]!='=') b=b*10+find(s);
        if(a==0&&b==0) return 0;
        printf("%d\n",a+b);
    }
    return 0;
}
