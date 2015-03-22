#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
const int MAX=10010;
int score[M56s);
			mp.insert(pair<string,int>(s,0) );
		}
		int base=0;
		map<string,int>::iterator iter;
		for(iter=mp.begin();iter!=mp.end();iter++){
			if(iter->first=="memory") break;
			else base++;
		}

		scanf("%d",&m);
		memset(score,0,sizeof(score));
		while(m--){
			tmp.clear();
			for(int i=0;i<n;i++){
				int ra;char s[100];
				scanf("%d%s",&ra,s);
				tmp.insert(pair<string,int>(s,ra));
			}
			int i=0;
			for(iter=tmp.begin();iter!=tmp.end();iter++){
				score[i++]+=iter->second;
			}
			int id=1;
			for(int i=0;i<n;i++) if(score[i]>score[base]) id++;
			printf("%d\n",id);
		}
	}
	return 0;
}
