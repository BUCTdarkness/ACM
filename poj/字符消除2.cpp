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
int change(string e){
    int len=e.size();
    if(len==0) return 0;
    string t="";int beg=0;
    e+="*";
    for(int i=1;i<len+1;i++){
        if(e[i]!=e[i-1]){
            if(beg==i-1) t+=e[i-1];
            beg=i;
        }
    }
    if(t.size()==len) return 0;
    return len-t.size()+change(t);
}
int main(){
	int t;
	while(~scanf("%d",&t)){
		while(t--){
            string str,e;
            cin>>str;
            int ans=0;
            for(int i=0;i<=str.size();i++){
                e=str;e.insert(i,"A");ans=max(ans,change(e));
                e=str;e.insert(i,"B");ans=max(ans,change(e));
                e=str;e.insert(i,"C");ans=max(ans,change(e));
            }
            printf("%d\n",ans);
		}
	}
	return 0;
}
