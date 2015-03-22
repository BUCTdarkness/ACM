#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
using namespace std;
const int MAXN=251;
const int MAXL=5100001;
struct Node{
	int id,fail;
	int next[26];
}ac[1100];
char pat[MAXL],word[MAXN][1001];
int cnt=0,ret=0;
void insert(char *s){
	int p=0;
	for(int i=0;s[i];i++){
		int index=s[i]-'A';
		if(!ac[p].next[index]) ac[p].next[index]=++cnt;
		p=ac[p].next[index];
	}
	ac[p].id=1;
}
void buildDFA(){
	queue<int> q;
	ac[0].fail=-1;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<26;i++){
			int tmp=ac[u].next[i],p;
			if(tmp){
				for(p=ac[u].fail;p!=-1;p=ac[p].fail){
					if(ac[p].next[i]){
						ac[tmp].fail=ac[p].next[i];break;
					}
				}
				if(p==-1) ac[tmp].fail=0;
				q.push(tmp);
			}
		}
	}
}
void search(char *pat){
	int p=0;
	for(int i=0;pat[i];i++){
		int index=pat[i]-'A';
		while(!ac[p].next[index]&&p) p=ac[p].fail;
		p=ac[p].next[index];
		int tmp=p;
		while(tmp&&ac[tmp].id!=-1){
			ret+=ac[tmp].id;
			ac[tmp].id=-1;
			tmp=ac[tmp].fail;
		}
	}
}
void init(){
	ret=0;cnt=0;
	memset(ac,0,sizeof(ac));
	memset(pat,0,sizeof(pat));
}
int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			init();
			int n;
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%s",word[i]);
				insert(word[i]);
			}
			getchar();
			char ch;
			int a,len=0;
			for(scanf("%c",&ch);ch!='\n';scanf("%c",&ch)){
				if(ch=='['){
					scanf("%d",&a);
					scanf("%c",&ch);
					for(int i=0;i<a;i++) pat[len++]=ch;
					scanf("%c",&ch);
				}
				else pat[len++]=ch;
			}
			buildDFA();
			search(pat);
			for(int i=0;i<len/2;i++) swap(pat[i],pat[len-1-i]);
			search(pat); 
			printf("%d\n",ret);
		}
	}
	return 0;	
}
