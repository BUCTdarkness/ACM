#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX=3131;
struct Shop{
    int price;
    char name[33];
}shop;
typedef __int64 ll;
int n,m,ans;
vector<Shop> Hash[MAX];
ll BKDRHash(char *str){
    ll seed=31,hash=0;
    while(*str){
        hash=hash*seed+(*str++);
    }
    return (hash & 0x7FFFFFFF) %MAX;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=0;i<MAX;i++) Hash[i].clear();
        for(int i=0;i<n;i++){
            scanf("%s",shop.name);
            shop.price=0;
            ll t=BKDRHash(shop.name);
            Hash[t].push_back(shop);
        }
        scanf("%d",&m);
        while(m--){
            for(int i=0;i<n;i++){
                scanf("%d%s",&shop.price,shop.name);
                ll t=BKDRHash(shop.name);
                for(int j=0;j<Hash[t].size();j++){
                    if(strcmp(shop.name,Hash[t][j].name)==0){
                        Hash[t][j].price+=shop.price;
                        if(strcmp(shop.name,"memory")==0)
                            ans=Hash[t][j].price;
                        break;
                    }
                }
            }
            int rank=1;
            for(int i=0;i<MAX;i++)
                for(int j=0;j<Hash[i].size();j++){
                    if(Hash[i][j].price>ans) rank++;
                }
            printf("%d\n",rank);
        }
    }
    return 0;
}
