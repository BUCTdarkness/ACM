#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXN=251;
const int MAXL=5100001;

struct node{
    int id,fail;
    int next[26];
}ac[500000];
char P1[MAXL],word[MAXN][1001];
int N,test,len,tn,ans;
queue<int> q;

void Insert(char *s){
    int len=strlen(s);
    int p=0;
    for (int i=0;i<len;i++){
        int index=s[i]-'A';
        if (!ac[p].next[index])  ac[p].next[index]=++tn;
        p=ac[p].next[index];
    }
    ac[p].id=1;
}

void Build(){
    ac[0].fail=-1;
    q.push(0);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int i=0;i<26;i++){
            int temp=ac[u].next[i],p;
            if (temp){
                for (p=ac[u].fail;p!=-1;p=ac[p].fail)
                    if (ac[p].next[i]) {ac[temp].fail=ac[p].next[i];break;}
                if (p==-1) ac[temp].fail=0;
                q.push(temp);
            }
        }
    }
}

void Read(){
    scanf("%d",&N);
    for (int i=1;i<=N;i++){
        scanf("%s",word[i]);
        Insert(word[i]);
    }
    int a;
    char ch;
    scanf("\n");
    for(scanf("%c",&ch);ch!='\n';scanf("%c",&ch)){
        if (ch=='['){
            scanf("%d",&a);
            scanf("%c",&ch);
            for (int i=1;i<=a;i++) P1[len++]=ch;
            scanf("%c",&ch);
        }
        else  P1[len++]=ch;
    }
    P1[len]='\0';
    Build();
}

void Solve(char *s){
    int len=strlen(s),p=0;
    for (int i=0;i<len;i++){
        int index=s[i]-'A';
        while (!ac[p].next[index]&&p) p=ac[p].fail;
        p=ac[p].next[index];
        int temp=p;
        while (temp&&ac[temp].id!=-1){
            ans+=ac[temp].id;
            ac[temp].id=-1;
            temp=ac[temp].fail;
        }
    }
}

void init(){
    len=tn=ans=0;
    memset(ac,0,sizeof(ac));
    memset(P1,0,sizeof(P1));
}

int main(){
    int t;
 //   cout<<sizeof(node)<<endl;
    scanf("%d",&t);
    while (t--){
        init();
        Read();
        Solve(P1);
        for (int i=0;i<len/2;i++) swap(P1[i],P1[len-1-i]);
        cout<<ans<<endl;
        Solve(P1);
        printf("%d\n",ans);
    }
    return 0;
}
