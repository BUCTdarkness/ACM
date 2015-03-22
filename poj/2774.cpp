//#pragma comment(linker, "/STACK:36777216")
#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cstring>
#include <climits>
#include <cassert>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>
using namespace std;
const int MAXN=200010;
int wa[MAXN],wb[MAXN],wv[MAXN],wsf[MAXN];
int sa[MAXN],rank[MAXN],height[MAXN];
char str1[MAXN],str2[MAXN];
int s[MAXN];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) wsf[i]=0;
    for(i=0;i<n;i++) wsf[x[i]=r[i]]++;
    for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
    for(i=n-1;i>=0;i--) sa[--wsf[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) wsf[i]=0;
        for(i=0;i<n;i++) wsf[wv[i]]++;
        for(i=1;i<m;i++) wsf[i]+=wsf[i-1];
        for(i=n-1;i>=0;i--) sa[--wsf[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
void calheight(int *r,int n){
    int i,j,k=0;
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}
int main(){
#ifdef ONLINE_JUDGE
#else
    freopen("in.txt","r",stdin);
#endif
    while(~scanf("%s%s",str1,str2)){
        int k=0;
        for(int i=0;str1[i];i++) s[k++]=str1[i]-'a'+2;
        s[k++]=28;
        for(int i=0;str2[i];i++) s[k++]=str2[i]-'a'+2;
        int len1=strlen(str1),len2=strlen(str2);
        s[k]=0;
        da(s,k+1,30);
        calheight(s,k);
       // for(int i=0;i<k;i++) cout<<" "<<sa[i];cout<<endl;
        int ans=0;
        for(int i=1;i<k;i++){
            if((sa[i]<len1&&sa[i-1]>len1)||(sa[i]>len1&&sa[i-1]<len1))
                ans=max(ans,height[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
