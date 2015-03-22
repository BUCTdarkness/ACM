#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdlib>
#define CLR(A) memset(A,0,sizeof(A))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>=0?(a):(-a))
using namespace std;
vector<set<int> > VEC(100100);
int data[100100],b[100100],c[100100],datar[100100];
int main()
{
    int n;
    while(scanf("%d", &n),n)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=0;i<=100000;i++)
            VEC[i].clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&data[i]);
            VEC[data[i]].insert(i);
            b[i]=data[i];
            c[i]=data[i];
        }
        for(int i=1;i<=n;i++){
            if(b[i]==1 && i-1>0)    b[i]=data[i-1];
            if(c[i]==1 && i+1<=n)   c[i]=data[i+1];
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j*j<=data[i];j++){
                if(data[i]%j==0){
                    int tmp=j,id;
                    if(VEC[tmp].size()!=0){
                        id=*(VEC[tmp].lower_bound(i));
                        if(VEC[tmp].lower_bound(i)!=VEC[tmp].end())
                            b[id]=data[i];
                    }
                    tmp=data[i]/j;
                    if(VEC[tmp].size()!=0){
                        id=*(VEC[tmp].lower_bound(i));
                        if(VEC[tmp].lower_bound(i)!=VEC[tmp].end())
                            b[id]=data[i];
                    }
                }
            }
        }

        for(int i=n;i>=1;i--){
            for(int j=2;j*j<=data[i];j++){
                if(data[i]%j==0){
                    int tmp=j,id;
                    set<int>::iterator p;
                    if(VEC[tmp].size()!=0){
                        p=VEC[tmp].upper_bound(i);
                        if(p!=VEC[tmp].begin()){
                            p--;id=*p;
                            c[id]=data[i];
                        }
                    }
                    tmp=data[i]/j;
                    if(VEC[tmp].size()!=0){
                        p=VEC[tmp].upper_bound(i);
                        if(p!=VEC[tmp].begin()){
                            p--;id=*p;
                            c[id]=data[i];
                        }
                    }
                }
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=((long long)b[i])*((long long)c[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
