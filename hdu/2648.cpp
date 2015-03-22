#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int MAX=10010;
struct SHOP{
    int ra;char nam[50];
}shop[MAX],tmp[MAX];
int score[MAX];
bool cmp(SHOP a,SHOP b){return strcmp(a.nam,b.nam)>0;}
int main(){
    int n,m;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++) scanf("%s",shop[i].nam);
        sort(shop,shop+n,cmp);
        int base;
        for(int i=0;i<n;i++){
            if(strcmp(shop[i].nam,"memory")==0){
                base=i;
                break;
            }
        }
        scanf("%d",&m);
        memset(score,0,sizeof(score));
        while(m--){
            for(int i=0;i<n;i++) scanf("%d%s",&tmp[i].ra,tmp[i].nam);
            sort(tmp,tmp+n,cmp);
            for(int i=0;i<n;i++) score[i]+=tmp[i].ra;
            int id=1;
            for(int i=0;i<n;i++) if(score[i]>score[base]) id++;
            printf("%d\n",id);
        }
    }
    return 0;
}
