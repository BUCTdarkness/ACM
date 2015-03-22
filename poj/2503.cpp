#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
map<string,string> mp;
map<string,bool> vis;
int main(){
    char a[20],b[20];
    char c;
    while(true){
        if((c=getchar())=='\n') break;
        else{
            a[0]=c;
            int i=1;
            while(true){
                c=getchar();
                if(c==' '){
                    a[i]='\0';break;
                }
                else  a[i++]=c;
            }
        }
        cin>>b;getchar();
        vis[b]=1;mp[b]=a;
    }

    char tmp[20];
    while(cin>>tmp){
        if(!vis[tmp]) cout<<"eh"<<endl;
        else cout<<mp[tmp]<<endl;
    }
    return 0;
}

