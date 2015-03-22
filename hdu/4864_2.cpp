#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<set>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAX=100005;
struct Task{
    int x,y;
}t[MAX];
bool cmp(Task a,Task b){if(a.x==b.x) return a.y>b.y;else return a.x>b.x;};
inline ll f(int x,int y){return 500*x+2*y;}
int main(){
    int n,m;
    while(cin>>n>>m){
        multiset<int> st[105];
        int maxlevel=0,cnt=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            st[y].insert(x);
            maxlevel=max(maxlevel,y);
        }
        for(int i=0;i<m;i++){scanf("%d%d",&t[i].x,&t[i].y);}
        sort(t,t+m,cmp);
        for(int i=0;i<m;i++){
            int u=t[i].x,v=t[i].y;
            for(int j=v;j<=maxlevel;j++){
                if(st[j].empty()) continue;
                multiset<int>::iterator it=st[j].lower_bound(u);
                if(it==st[j].end()||*it<u) continue;
                else{
                    cnt++;sum+=f(u,v);
                    st[j].erase(it);
                    break;
                }
            }
        }
        cout<<cnt<<" "<<sum<<endl;
    }
    return 0;
}

