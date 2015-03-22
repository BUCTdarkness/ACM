#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<bitset>
using namespace std;
#define CLR  memset(A,0,sizeof(A))
int main(){
    string str;
    while(cin>>str&&str[0]!='*'){
        int len=str.size();
        if(len<=2){
            cout<<str<<" is surprising."<<endl;
            continue;
        }
        bool flag=true;
        for(int d=1;d<=len-1;d++){
            map<string,bool> mp; mp.clear();
            for(int i=0;i<len&&i+d<len;i++){
                char s[]={str[i],str[i+d],'\0'};
                if(!mp[s]){
                    mp[s]=true;
                }
                else{
                    flag=false;break;
                }
            }
            if(!flag) break;
        }
        if(flag) cout<<str<<" is surprising."<<endl;
        else cout<<str<<" is NOT surprising."<<endl;
    }
    return 0;
}
