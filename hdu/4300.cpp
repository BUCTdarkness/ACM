#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 100100
using namespace std;
char A[MAXN];
char B[MAXN];
char Tran[30];
int fail[MAXN];
int kmp(char *pat){
    int ret=0;
    int L=strlen(pat);
    memset(fail,-1,sizeof(fail));
    for(int i=0;pat[i];i++)
		B[i]=Tran[A[i]-'a'];
	B[L]=0;
    for(int i=1;pat[i];i++){
        int k;
        for(k=fail[i-1];k>=0&&pat[i]!=B[k+1];k=fail[k]);
        if(B[k+1]==pat[i]){
            fail[i]=k+1;
        }
    }
    int i=0,j=0;
    ret=L-1;
    while(fail[ret]>(L/2-1))//²»Ïà»¥ÖØµş 
        ret=fail[ret];
    return fail[ret];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		char getin[30];
		scanf("%s",getin);
		for(int i=0;getin[i];i++){
			Tran[getin[i]-'a']=i+'a';
		}
		scanf("%s",A);
		int L=strlen(A);
		int ans=kmp(A);
	//	cout<<ans<<endl;
		if(ans!=-1)
		{
			ans=L-ans-1;
//			cout<<"ans!=-1 "<<ans<<endl;
			for(int i=0;i<ans;i++)
				printf("%c",A[i]);
			for(int i=0;i<ans;i++)
		    	printf("%c",B[i]);
		}
		else
		{
		    for(int i=0;A[i];i++)
		        printf("%c",A[i]);
	        for(int i=0;A[i];i++)
	            printf("%c",B[i]);
		}
		puts("");
	}
	return 0;
}
/*
1000
abcdefghijklmnopqrstuvwxyz

*/