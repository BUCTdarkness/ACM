//以i结尾的最长串的长度
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
using namespace std;
#define lowbit(x) (x)&(-x)
#define CLR(A) memset(A,0,sizeof(A))
int cnt[28];
int main(){
    int T,k;
    scanf("%d",&T);
    string str;
    while(T--){
        cin>>str>>k;
        int start=0;CLR(cnt);
        __int64 ans=0;
        for(int i=0;str[i];i++){
            int x=str[i]-'a';
            cnt[x]++;
            if(cnt[x]>k){
                while(str[start]!=str[i]){
                    cnt[str[start]-'a']--;
                    start++;
                }
                cnt[str[start]-'a']--;
                start++;
            }
            ans+=i-start+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
