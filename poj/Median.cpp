#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
multiset<int> st;
multiset<int>::iterator it1;
multiset<int>::iterator tmp;
multiset<int>::iterator it;
inline void print(){
    int len=st.size();
    if(len==0) printf("Empty!\n");
    else if(len&1) printf("%d\n",*it1);
    else{
        tmp=it1;
        tmp++;
        long long sum=(long long)*it1+(long long)*tmp;
        if(sum%2==0) printf("%lld\n",sum/2);
        else printf("%.1lf\n",sum/2.0);
    }
}
int main(){
    int T;
    while(~scanf("%d",&T)){
        while(T--){
        int n;
        scanf("%d",&n);
        st.clear();
        char ord[30];int x;
        while(n--){
            scanf("%s%d",ord,&x);
            switch(ord[0]){
            case 'a':
                st.insert(x);
                if(st.size()==1){
                    it1=st.begin();
                }
                else{
                    if((st.size()%2==1)&&x>=*it1) it1++;
                    else if((st.size()%2==0)&&x<*it1) it1--;
                }
                print();
                break;
            case 'r':
                it=st.find(x);
                if(it==st.end()){
                    printf("Wrong!\n");
                    continue;
                }
                else if(*it1==x){
                    it=it1;
                    if(st.size()%2==1) it1--;
                    else it1++;
                }
                else{
                    if(st.size()%2==1&&x>=*it1) it1--;
                    else if(st.size()%2==0&&x<*it1) it1++;
                }
                st.erase(it);
                print();
                break;
            }
        }
        }
    }
    return 0;
}
