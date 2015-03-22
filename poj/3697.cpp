#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cstdlib>
#define CLR(A) memset(A,0,sizeof(A))
using namespace std;
typedef long long ll;
const int MAX=10006;
const int mod=10000007;
int mp[mod];
int q[MAX];
bool vis[MAX];
int getkey(int x){
    int i=1,y=x;
    y%=mod;
    while(mp[y]!=-1&&mp[y]!=x){
        y+=i*i;
        i++;
        if(y>=mod)
            y%=mod;
    }
    return y;
}

int main(){
    int n,m;
    int ncas=0;
    while(~scanf("%d%d",&n,&m)&&(n+m)){
        memset(mp,-1,sizeof(mp));
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            a=a*10000+b;
            mp[getkey(a)]=a;
        }
        CLR(vis);
        int head=0,tail=0;
        q[tail++]=1;
        vis[1]=1;
        int ans=0;
        while(head!=tail){
            int tmp=q[head++];
            for(int i=2;i<=n;i++){
                if(!vis[i]&&mp[getkey(tmp*10000+i)]==-1&&mp[getkey(i*10000+tmp)]==-1){
                    vis[i]=1;
                    q[tail++]=i;
                    ans++;
                }
            }
        }
        cout<<"Case "<<++ncas<<": "<<ans<<endl;
    }
    return 0;
}
