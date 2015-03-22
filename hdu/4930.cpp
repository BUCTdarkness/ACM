#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
const int MAX=20;
char stra[MAX],strb[MAX];
int va[MAX],vb[MAX];
int na,nb;
void change(char s[],int v[]){
    for(int i=0;i<strlen(s);i++){
        if(s[i]>='3'&&s[i]<='9') v[i]=s[i]-'0';
        if(s[i]=='T') v[i]=10;
        if(s[i]=='J') v[i]=11;
        if(s[i]=='Q') v[i]=12;
        if(s[i]=='K') v[i]=13;
        if(s[i]=='A') v[i]=14;
        if(s[i]=='2') v[i]=15;
        if(s[i]=='X') v[i]=16;
        if(s[i]=='Y') v[i]=17;
    }
}
int Bomb(int v[],int len){
    int cnt=1,i;
    for(i=len-1;i>=0;i--){
        if(v[i]<16) break;
    }
    if(i<3) return 0;
    i--;
    for(;i>=0;i--){
        if(v[i]==v[i+1])
            cnt++;
        else
            cnt=1;
        if(cnt==4) return v[i];
    }
    return 0;
}

int Nuke(int v[],int len){
    if(len<2) return 0;
    if(v[len-1]==17&&v[len-2]==16) return 1;
    return 0;
}

int Pair(int v[],int len){
    if(len<2) return 0;
    for(int i=len-2;i>=0;i--){
        if(v[i]==v[i+1]) return v[i];
    }
    return 0;
}

int Trio(int v[],int len){
    if(len<3) return 0;
    int cnt=1;
    for(int i=len-2;i>=0;i--){
        if(v[i]==v[i+1]) cnt++;
        else cnt=1;
        if(cnt==3) return v[i];
    }
    return 0;
}

int Trio_Solo(int v[],int len){
    if(len<4) return 0;
    int x=Trio(v,len);
    if(x && x!=v[0] && x!=v[len-1])
    return Trio(v,len);
}

int Trio_Pair(int v[],int len){
    if(len<5) return 0;
    int x=Trio(v,len);
    int pos;
    if(x!=0){
        pos=lower_bound(v,v+len,x)-v;
        int t1=Pair(v,pos);
        if(t1!=0) return x;
        pos++;//·ÀÖ¹Òç³ö
        for(pos;pos<len;pos++){
            if(v[pos]!=v[pos-1]) break;
        }
        int t2=Pair(v+pos,len-pos);
        if(t2!=0) return x;
    }
    return 0;
}

int Four_Dual(int v[],int len){
    if(len<6) return 0;
    return Bomb(v,len);
}

bool Drop_All(int v[],int len){
    if(len>7) return false;
    if(len==6&&Four_Dual(v,len)!=0) return 1;
    if(len==5&&Trio_Pair(v,len)!=0) return 1;
    if(len==4&&(Trio_Solo(v,len)!=0||Bomb(v,len)!=0)) return 1;
    if(len==3&&Trio(v,len)!=0) return 1;
    if(len==2&&Pair(v,len)!=0&&Nuke(v,len)) return 1;
    if(len==1) return 1;
    return 0;
}

bool check(int v1[],int len1,int v2[],int len2){
    int x,y;
    if(Drop_All(v1,len1)) return true;
 //cout<<1<<endl;
    if(Nuke(v1,len1)!=0) return true;
//cout<<2<<endl;
    if(Nuke(v2,len2)!=0) return false;
    x=Bomb(v1,len1);y=Bomb(v2,len2);
    if(x && y==0) return true;
    if(x==0 && y) return false;
    if(x && x>=y) return true;
    if(y>x)    return false;

    if(v1[len1-1]>=v2[len2-1]) return true;
//cout<<4<<endl;
    x=Pair(v1,len1);y=Pair(v2,len2);
    if(x && x>=y) return true;
  //  cout<<5<<endl;
    x=Trio(v1,len1);y=Trio(v2,len2);
    if(x && x>=y) return true;
//cout<<6<<endl;
    x=Trio_Solo(v1,len1);y=Trio_Solo(v2,len2);
    if(x && x>=y) return true;
//cout<<7<<endl;
    x=Trio_Pair(v1,len1);y=Trio_Pair(v2,len2);
    if(x && x>=y) return true;
//cout<<8<<endl;
    x=Four_Dual(v1,len1);y=Four_Dual(v2,len2);
    if(x && x>=y) return true;
 //   cout<<9<<endl;
 //   cout<<10<<endl;
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s%s",stra,strb);
        na=strlen(stra);nb=strlen(strb);
        change(stra,va);change(strb,vb);
        sort(va,va+na);sort(vb,vb+nb);
        if(check(va,na,vb,nb)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
