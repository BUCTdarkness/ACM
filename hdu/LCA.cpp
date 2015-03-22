#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<cstdlib>
#include<bitset>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
#define MP(A,B) make_pair(A,B)
int n,m;
map<string,int> mp;
map<int,string> mp1;
int pa[1000];
bool vis[1000];
int main(){
    scanf("%d",&n);
    mp.clear();mp1.clear();CLR(vis);CLR(pa);
    string a,b;
    int cnt=1;
    while(n--){
        cin>>a>>b;
        if(mp[a]==0) {mp[a]=cnt++;mp1[cnt-1]=a;}
        if(mp[b]==0) {mp[b]=cnt++;mp1[cnt-1]=b;}
        pa[mp[b]]=mp[a];
    }
    scanf("%d",&m);
    while(m--){
        cin>>a>>b;
        if(a==b) {
            cout<<a<<endl;
            continue;
        }
        CLR(vis);
        int t1=mp[a],t2=mp[b];
        while(t1!=0){
            vis[t1]=1;t1=pa[t1];
        }
        bool flag=0;string ans="";
        while(t2!=0){
            if(vis[t2]){flag=1;ans=mp1[t2];break;}
            t2=pa[t2];
        }
        if(flag){
            cout<<ans<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
