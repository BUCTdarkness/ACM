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
int n;
struct Node{
    int de,v;
    friend bool operator < (const Node &a,const Node &b){
        return a.de>b.de;
    }
}p[MAX];
int main(){
    while(scanf("%d",&n)!=EOF){
        CLR(p);
        int maxt=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i].v,&p[i].de);
            maxt=max(maxt,p[i].de);
        }
        sort(p,p+n);
        int pos=0;
        ll ans=0;
        priority_queue<int> q;
        while(maxt>=1){
            while(pos<n&&p[pos].de>=maxt){
                q.push(p[pos++].v);
            }
            if(!q.empty()){
                ans+=q.top();
                q.pop();
            }
            maxt--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
