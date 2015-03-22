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
int main(){
    int t;
    cin>>t;
        while(t--){
            int n,m;
            ll ans1=0,ans2=0;
            cin>>n>>m;
            for(int i=0;i<n;i++){
                int x;cin>>x;
                ans1+=x;
            }
            for(int i=0;i<m;i++){
                int x;cin>>x;
                ans2+=x;
            }
            if(ans1>ans2){
                cout<<"Calem"<<endl;
            }else if(ans1<ans2){
                cout<<"Serena"<<endl;
            }else{
                cout<<"Draw"<<endl;
            }
        }
    return 0;
}
