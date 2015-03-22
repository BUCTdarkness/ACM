#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
int a[105],b[105];
int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        CLR(a);CLR(b);
        for(int i=0;i<str1.size();i++) a[str1[i]-'A']++;
        for(int i=0;i<str2.size();i++) b[str2[i]-'A']++;
        sort(a,a+26);sort(b,b+26);
        bool flag=true;
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                flag=false;break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
