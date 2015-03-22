#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;
const int gradeup[5]={100,84,79,74,69};
const int gradedown[5]={85,80,75,70,60};
double gpa[200];
void init(){
    for(int i=0;i<=200;i++){
        gpa[i]=2.0;
        if(i>=60&&i<70) gpa[i]=2.0;
        if(i>=70&&i<75) gpa[i]=2.5;
        if(i>=75&&i<80) gpa[i]=3.0;
        if(i>=80&&i<85) gpa[i]=3.5;
        if(i>=85) gpa[i]=4.0;
    }
}
int main(){
    init();
    int T;
    while(~scanf("%d",&T)){
        while(T--){
            int avg,n;
            scanf("%d%d",&avg,&n);
            int sum=avg*n;int tmp=sum;
            double gpama=0,gpami=0;
            cout<<tmp<<endl;
            for(int i=1;i<=n;i++){
                int r=n-i,k;
                for(int j=4;j>=0&&r>0;j--){
                    k=j;
                    if(tmp-gradedown[j]<60*r) continue;
                    else break;
                }
                if(r==0){
                    gpama+=gpa[tmp]; break;
                }
                tmp-=gradedown[k];
                gpama+=gpa[gradedown[k]];
            }
            tmp=sum;
            for(int i=1;i<=n;i++){
                int r=n-i,k;
                for(int j=0;j<=4;j++){
                    k=j;
                    if(tmp-gradeup[j]<100*r) continue;
                    else break;
                }
                if(r==0){
                    gpami+=gpa[tmp]; break;
                }
                tmp-=gradeup[k];
                gpami+=gpa[gradeup[k]];
            }
            printf("%.4lf %.4lf\n",gpami/n,gpama/n);
        }
    }
    return 0;
}

