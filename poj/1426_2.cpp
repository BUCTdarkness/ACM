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
queue<ll> q;
ll n;
void bfs(){
    q.push(1);
    while(!q.empty()){
        ll tmp=q.front();
        q.pop();
        if(tmp%n==0){
            cout<<tmp<<endl;
            break;
        }
        else{
            q.push(tmp*10);
            q.push(tmp*10+1);
        }
    }
}
int main(){
    while(cin>>n&&n){
        while(!q.empty()) q.pop();
        bfs();
    }
    return 0;
}
