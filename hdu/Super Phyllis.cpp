#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
map<string,int> mp1;
map<int,string> mp2;
bool g[210][210];
int d[210];
vector<string> ans;
vector<int> vec[210];
void bfs(int v){
    queue<int> q;
    CLR(d);
    q.push(v);d[v]=1;
    while(!q.empty()){
        int tmp=q.front();q.pop();
        for(int i=0;i<vec[tmp].size();i++){
            int tt=vec[tmp][i];
            if(!vec[tmp][i]) continue;
            if(!d[tt]){
                d[tt]=d[tmp]+1;
                q.push(tt);continue;
            }
            if(d[tt]==2&&g[v][tt]){
                string ttt=mp2[v]+","+mp2[tt];
                ans.push_back(ttt);
                g[v][tt]=0;
            }
        }
    }
}
int main(){
    int n,kase=0;
    while(cin>>n&&n){
        mp1.clear();mp2.clear();
        int cnt=0;CLR(g);
        for(int i=0;i<=210;i++) vec[i].clear();
        ans.clear();
        for(int i=0;i<n;i++){
            string a,b;
            cin>>a>>b;
            if(!mp1[a]){
                mp1[a]=++cnt;
                mp2[cnt]=a;
            }
            if(!mp1[b]){
                mp1[b]=++cnt;
                mp2[cnt]=b;
            }
            g[mp1[a]][mp1[b]]=1;
            vec[mp1[a]].push_back(mp1[b]);
        }
        for(int i=1;i<=cnt;i++) bfs(i);
        sort(ans.begin(),ans.end());
		cout<<"Case "<<++kase<<": "<<ans.size();
		for(int i=0;i<ans.size();i++)
		    cout<<' '<<ans[i];
		cout<<endl;
    }
    return 0;
}

