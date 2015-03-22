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
const char ch[63]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int Dig[200];
int Prim[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,83,89,93};
long long fc[100];
vector<int>factor;
long long fnum[100],fcnt;
int main(){
	for(int i=0;i<62;i++)
		Dig[ch[i]]=i;
	long long K;
	char str[10000];
	while(~scanf("%s%lld",str,&K)){
		long long L=strlen(str);
		long long tmp=1;
		long long num=0;
		for(int i=L-1;i>=0;i--){
			num+=(Dig[str[i]])*tmp;
			tmp*=K;
		}
		if(num==0){
			printf("%d\n",0);
			continue;
		}
		factor.clear();
		fcnt=0;
		int K1=K;
		for(int i=0;Prim[i]<=K1;i++){
			if(K1%Prim[i]==0){
				factor.push_back(Prim[i]);
				fnum[fcnt]=0;
				while(K1%Prim[i]==0){
					fnum[fcnt]++;
					K1/=Prim[i];
				}
				fcnt++;
			}
		}
		memset(fc,0,sizeof(fc));
		int sz=factor.size();
		for(int i=0;i<sz;i++){
			long long t=num;
			long long k=factor[i];
			while(t){
				t/=k;
				fc[i]+=t;
			}
			fc[i]=fc[i]/(fnum[i]);
		}
		long long mini=fc[0];
		for(int i=0;i<sz;i++)
		    mini=min(mini,fc[i]);
		printf("%lld\n",mini);
	}
}
