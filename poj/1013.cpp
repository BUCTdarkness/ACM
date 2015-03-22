#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
typedef long long ll;

int main(){
    int T;
    while(~scanf("%d",&T)){
        while(T--){
            char left[5][10],right[5][10],status[5][10];
            for(int i=0;i<3;i++){
                cin>>left[i]>>right[i]>>status[i];
            }
            int cnt['L'+1]={0};
            bool ok['L'+1]={0};
            for(int i=0;i<3;i++){
                switch(status[i][0]){
                case 'u':
                    for(int j=0;left[i][j];j++){
                        cnt[left[i][j]]++;
                        cnt[right[i][j]]--;
                    }
                    break;
                case 'd':
                    for(int j=0;right[i][j];j++){
                        cnt[left[i][j]]--;
                        cnt[right[i][j]]++;
                    }
                    break;
                case 'e':
                    for(int j=0;left[i][j];j++){
                        ok[left[i][j]]=1;ok[right[i][j]]=1;
                    }
                }
            }
            int ret=0,ma=0;
            for(int i='A';i<='L';i++){
                if(ok[i]) continue;
                if(ret<abs(cnt[i])){
                    ret=abs(cnt[i]);ma=i;
                }
            }
            printf("%c is the counterfeit coin and it is ",ma);
            if(cnt[ma]>0) printf("heavy. \n");
            else printf("light. \n");
        }
    }
    return 0;
}



