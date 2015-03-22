#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
int m1[30],m2[30];
bool findsame(string &a,string &b){
    int j=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==b[j]) j++;
        if(j==b.size()) return true;
    }
    return false;
}
int main(){
    string a,b;
    while(cin>>a>>b){
       if(a.size()==b.size()){
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(a!=b){
                cout<<"need tree"<<endl;
            }
            else{
                cout<<"array"<<endl;
            }
       }
       else{
            if(findsame(a,b)) cout<<"automaton"<<endl;
            else{
                sort(a.begin(),a.end());
                sort(b.begin(),b.end());
                if(findsame(a,b)){
                    cout<<"both"<<endl;
                }
                else{
                    cout<<"need tree"<<endl;
                }
            }
       }
    }
    return 0;
}
