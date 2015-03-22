#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int MAX=10010;
int p[MAX];
void init(){
    for(int i=0;i<MAX;i++) p[i]=i;
}
int find_set(int v){
    return p[v]==v?p[v}=find_set(p[v]);
}
void union_set(int a,int b){
    a=find_set(a);b=find_set(b);
    if(a!=b){
        p[a]=p[b];
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int x,y;
        while(n--){
            scanf("%d%d",&x,&y);
            for(int i=x;i<=y-1;i++){
                union_set(i,i+1);
            }
        }
        scanf("%d%d",&x,&y);
        if(find_set(x)==find_set(y)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


