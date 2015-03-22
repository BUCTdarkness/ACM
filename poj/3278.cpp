#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100000;
int n,k;
int vis[MAXN+10];
struct Step{
    int x,steps;
    Step(int xx,int s){
        x=xx;steps=s;
    }
};
queue<Step> q;
int main(){
    while(cin>>n>>k){
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        q.push(Step(n,0));
        vis[n]=1;
        while(!q.empty()){
            Step s=q.front();
            if(s.x==k){
                cout<<s.steps<<endl;break;
            }
            else{
                if(s.x-1>=0&&!vis[s.x-1]){
                    q.push(Step(s.x-1,s.steps+1));
                    vis[s.x-1]=1;
                }
                if(s.x+1<=MAXN&&!vis[s.x+1]){
                    q.push(Step(s.x+1,s.steps+1));
                    vis[s.x+1]=1;
                }
                if(s.x*2<=MAXN&&!vis[s.x*2]){
                    q.push(Step(s.x*2,s.steps+1));
                    vis[s.x*2]=1;
                }
                q.pop();
            }
        }
    }
    return 0;
}
