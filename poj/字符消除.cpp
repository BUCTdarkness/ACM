#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
using namespace std;
char str[110]={'\0'},s[110]={'\0'},ret[110]={'\0'};
inline void change(int x){
    bool fir=0;
    while(x-1>=0&&str[x]==str[x-1]) x--;
 //   cout<<"x="<<x<<" "<<str<<endl;
    while(true){
        bool flag=0;
        int cnt=0;for(int i=0;i<110;i++) ret[i]='\0';
        char pre='\0';
        int len=1;
        for(int i=0;i<strlen(str);i++){
            if(!fir&&i==x){
                fir=1;flag=1;pre=str[x];
                while(i+1<strlen(str)&&str[i+1]==str[x])i++;
                continue;
            }
            if(str[i]!=pre){
                len=1;pre=str[i];ret[cnt++]=str[i];
            }
            else{
                flag=1;
                if(len==1&&cnt>0) cnt--;
                len++;
            }
        }
        ret[cnt]='\0';
        if(!flag) break;
        for(int i=0;i<strlen(ret);i++) str[i]=ret[i];str[strlen(ret)]='\0';
    }
}
int main(){
	int t;
	while(~scanf("%d",&t)){
		while(t--){
			scanf("%s",str);
			int len=strlen(str);
            int ans=0;
            for(int j=0;j<strlen(str);j++) s[j]=str[j];s[strlen(str)]='\0';
            for(int i=0;i<len;i++){
                change(i);
         //       cout<<ret<<endl;
                int tmp=strlen(ret);
                ans=max(ans,len+1-tmp);
                for(int j=0;j<strlen(s);j++) str[j]=s[j];str[strlen(s)]='\0';
            }
            printf("%d\n",ans);
		}
	}
	return 0;
}
