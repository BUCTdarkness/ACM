#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int MAX=2100000;
struct Node{
    char str[90];
};
vector<Node> g;
unsigned int BKDHash(char *s){
    unsigned int seed=131;
    unsigned int ret=0;
    while(*s){
        ret=ret*seed+*s++;
    }
    return (ret&0x7FFFFFFF)%100007;
}
int find(char *s){
    int v=BKDHash(s);
    for(int i=0;i<g.size();i++){
        if(strcmp(g[i].str,s)==0){
            return i;
        }
    }
    return -1;
}
int main(){

    return 0;
}


