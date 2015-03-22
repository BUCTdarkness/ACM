#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<cstdlib>
#include<map>
using namespace std;
#define CLR(A) memset(A,0,sizeof(A))
map<string,set<string> > mp;
vector<string> g1,g2,ret;
char word[300000];
int main(){
    int n,m,cnt=0;
    while(~scanf("%d",&n)){
        mp.clear();g1.clear();g2.clear();ret.clear();

        //程序读入
        for(int i=0;i<n;i++){
            string a,b;
            cin>>a;
            getchar();
            gets(word);
            istringstream ss(word);
            while(ss>>b){
                g1.push_back(b);
				mp[b].insert(a);
            }
        }
        sort(g1.begin(),g1.end());
        cnt=unique(g1.begin(),g1.end())-g1.begin();

        //query 读入
        scanf("%d",&m);
        getchar();
        string t;
        while(m--){
        	//读入
            gets(word);
            istringstream ss(word);
            g2.clear();ret.clear();
            bool flag=0;
            while(ss>>t){
				g2.push_back(t);
            }

            //枚举处理
            int len=g2.size();
			for(int i=0;i<cnt;i++){
				int j;
				for(j=0;j<len;j++){
					if(mp[g1[i]].find(g2[j])==mp[g1[i]].end()) break;
				}
				if(j==len){
					flag=1;
					ret.push_back(g1[i]);
				}
			}

			//输出
			if(flag==0) cout<<"NO"<<endl;
			else{
				sort(ret.begin(),ret.end());
				for(int k=0;k<ret.size();k++){
					if(k==0) cout<<ret[k];
					else cout<<" "<<ret[k];
				}
				cout<<endl;
			}
        }

    }
    return 0;
}
